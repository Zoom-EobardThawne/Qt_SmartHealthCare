#include <stdio.h>
#include <string.h>
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <json/json.h>
#include "handler_client.h"

#define SUCCESS_STATE 0
#define FAILE_STATE  1

typedef void (*handler_client_t)(int sockfd,json_object *object);

handler_client_t client_request_handler[]={

	handler_user_register,
	handler_user_login,
	handler_user_get_password,
	handler_doctor_register,
	handler_doctor_information_get,
	handler_doctor_id_information_get,
	handler_doctor_login,
	handler_doctor_get_password,
	handler_user_doctor_appointment,
	handler_user_feature_data,
	handler_chart_data,
	handler_user_information_get,
	handler_doctor_opinion,
	handler_doctor_message_get,
	NULL
	
};

void parse_json_data(int client_fd,const char *json_string)
{
	int function_id;
	json_object *object;
	handler_client_t handler;
	json_object *function_id_object;

	object = json_tokener_parse(json_string);
	if(object == NULL){
		printf("The json data is error!\n");
		return;
	}

	function_id_object = json_object_object_get(object,"function_id");
	if(function_id_object == NULL){
		printf("The json object no such functionId filed!\n");
		goto error_1;
	}

	function_id = json_object_get_int(function_id_object);
	printf("function_id : %d\n",function_id);


	handler =client_request_handler[function_id];
	if(handler){
		(*handler)(client_fd,object);
	}

error_1:	
	json_object_put(object);

	return;
}




void *do_client(void *arg)
{	
	int ret;
	char *buf=NULL;
	int client_fd = *((int *)arg);
	extern char* recv_protocol_data(int);
		buf=recv_protocol_data(client_fd);
		if(buf){
		
		
		parse_json_data(client_fd,buf);

		free_protocol_data(buf);
		}	
	close(client_fd);
}



int main(void)
{
	int fd;
	int ret;
	int client_fd;
	pthread_t tid;
	struct sockaddr_in server_addr;

	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd < 0){
		perror("Fail to socket");
		return -1;
	}

	printf("fd = %d\n",fd);
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port   = htons(8888);
	server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	ret = bind(fd,(const struct sockaddr *)&server_addr,sizeof(server_addr));
	if(ret < 0){
		perror("Fail to bind");
		return -1;
	}

	ret = listen(fd,128);
	if(ret < 0){
		perror("Fail to listen");
		return -1;
	}

	printf("listen ....\n");

	while(1){

		client_fd = accept(fd,NULL,NULL);
		if(client_fd < 0){
			perror("Fail to accept");
			return -1;
		}

		printf("client_fd : %d\n",client_fd);
	
		pthread_create(&tid,NULL,do_client,&client_fd);
		pthread_detach(tid);
	}

	return 0;
}
