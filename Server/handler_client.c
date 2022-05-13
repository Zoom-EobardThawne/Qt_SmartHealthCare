#include <stdio.h>
#include <string.h>
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <json/json.h>
#include "handler_client.h"
#include"doctor.h"
#include "user.h"

json_object *create_client_json_object(int function_id, int state){

	json_object *object;

	object = json_object_new_object();
	if(object == NULL){
	
		printf("Fail to json object new object!\n");
		return NULL;
	}

	json_object_object_add(object,"function_id",json_object_new_int(function_id));
	json_object_object_add(object,"state",json_object_new_int(state));

	return object;
}

void destory_client_json_object(json_object *client_object)
{
	json_object_put(client_object);
}

void reply_client_result(int client_fd,json_object *object)
{
	int ret;
	const char *json_string;
	
	json_string = json_object_to_json_string(object);
	if(json_string == NULL){
		printf("Fail to json object to json_string!\n");
		return;
	}

	ret = send(client_fd,json_string,strlen(json_string),0);
	if(ret < 0){
		perror("Fail to send");
	}

	printf("reply client : %s\n",json_string);

	return;
}

void handler_user_register(int client_fd,json_object *object)
{

	int state = user_register(object);
	json_object *client_object = create_client_json_object(USER_REGISTER,state);
	if(client_object){
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	return;
}

void handler_user_login(int client_fd,json_object *object)
{
	
	int state = user_login(object);
	json_object *client_object = create_client_json_object(USER_LOGIN,state);
	if(client_object){
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	return;
}


void handler_doctor_login(int client_fd,json_object *object)
{
	
	int state = doctor_login(object);
	json_object *client_object = create_client_json_object(DOCTOR_LOGIN,state);
	if(client_object){
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	return;
}


void handler_user_get_password(int client_fd,json_object *object)
{
	char *password = "null";
	int state =user_get_password(object,&password);
	json_object *client_object = create_client_json_object(USER_GET_PASSWORD,state);

	if(client_object){
	
		json_object_object_add(client_object,"password",json_object_new_string(password));
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	if(!state && password){
		free(password);
	}
	return;
}

 

void handler_doctor_get_password(int client_fd,json_object *object)
{
	char *password = "null";
	int state =doctor_get_password(object,&password);
	json_object *client_object = create_client_json_object(DOCTOR_GET_PASSWORD,state);

	if(client_object){
	
		json_object_object_add(client_object,"password",json_object_new_string(password));
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	if(!state && password){
		free(password);
	}
	return;
} 


void handler_doctor_register(int client_fd,json_object *object)
{

	int state = doctor_register(object);
	json_object *client_object = create_client_json_object(DOCTOR_REGISTER,state);
	if(client_object){
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	return;

}
void add_doctor_information(json_object *object,doctor_information_table_t *doctor_table){

	int i;
	int j;
	int index=0;
	json_object *doctor_array;

	doctor_array=json_object_new_array();
	if(!doctor_array){
		printf("Fail to json object new array!\n");
		return ;
	
	}
	for(i=0,index=doctor_table->ncolum;i<doctor_table->nrow;i++){
	
		json_object *object;
		object=json_object_new_object();
		for(j=0;j<doctor_table->ncolum;j++){
			json_object_object_add(object,doctor_table->result[j],json_object_new_string(doctor_table->result[index++]));

		}
		json_object_array_add(doctor_array,object);
	}
	
		json_object_object_add(object,"doctor_info",doctor_array);
		printf("json array : %s\n",json_object_to_json_string(object));
		return;


}


void add_doctor_message(json_object *object,doctor_information_table_t *doctor_table){

	int i;
	int j;
	int index=0;
	json_object *doctor_array;

	doctor_array=json_object_new_array();
	if(!doctor_array){
		printf("Fail to json object new array!\n");
		return ;
	
	}
	for(i=0,index=doctor_table->ncolum;i<doctor_table->nrow;i++){
	
		json_object *object;
		object=json_object_new_object();
		for(j=0;j<doctor_table->ncolum;j++){
			json_object_object_add(object,doctor_table->result[j],json_object_new_string(doctor_table->result[index++]));

		}
		json_object_array_add(doctor_array,object);
	}
	
		json_object_object_add(object,"doctor_opinion",doctor_array);
		printf("json array : %s\n",json_object_to_json_string(object));
		return;


}

void add_user_information(json_object *object,doctor_information_table_t *user_table)
{

	int i;
	int j;
	int index=0;
	json_object *user_array;

	user_array=json_object_new_array();
	if(!user_array){
		printf("Fail to json object new array!\n");
		return ;
	
	}
	for(i=0,index=user_table->ncolum;i<user_table->nrow;i++){
	
		json_object *object;
		object=json_object_new_object();
		for(j=0;j<user_table->ncolum;j++){
			json_object_object_add(object,user_table->result[j],json_object_new_string(user_table->result[index++]));

		}
		json_object_array_add(user_array,object);
	}
	
		json_object_object_add(object,"user_info",user_array);
		printf("json array : %s\n",json_object_to_json_string(object));
		return;


}


void free_doctor_table(doctor_information_table_t *doctor_table){


	if(doctor_table->result){
	
		sqlite3_free_table(doctor_table->result);
	}
	return ;


}

void free_feature_data_table(feature_data_table_t *feature_data_table){


	if(feature_data_table->result){
	
		sqlite3_free_table(feature_data_table->result);
	}
	return ;


}
void add_doctor_picture_information(json_object *client_object,const char *id){


	FILE *fp;
	long size;
	char *buffer=NULL;

	char command[1024];
	sprintf(command,"base64 doctor_picture/%s.jpg > base64.txt",id);
	system(command);
	
	fp=fopen("base64.txt","r");
	if(fp==NULL){
		perror("Fail to open base64.txt");
		return ;
	}

	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	fseek(fp,0,SEEK_SET);
	buffer=(char *)malloc(size);
	fread(buffer,size,sizeof(char),fp);
	fclose(fp);
	remove("base64.txt");
	json_object_object_add(client_object,"picture",json_object_new_string(buffer));

	if(buffer){
	free(buffer);
	}
	return;
}

void handler_doctor_information_get(int client_fd,json_object *object)
{

	int state=0;
	json_object *client_object;
	doctor_information_table_t doctor_information_table;

	extern doctor_information_table_t get_all_doctor_information(void);
	doctor_information_table=get_all_doctor_information();
	if(!doctor_information_table.nrow){
		state=1;
	}

	client_object =create_client_json_object(DOCTOR_INFORMATION_GET,state);
	if(client_object){
		if(doctor_information_table.nrow){
			add_doctor_information(client_object,&doctor_information_table);
		
		}
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

	free_doctor_table(&doctor_information_table);
	return;

}


void handler_doctor_id_information_get(int client_fd,json_object *object)
{

	int state=0;
	json_object *id_object;
	json_object *client_object;
	const char *id =NULL;
	doctor_information_table_t doctor_information_table;

	extern doctor_information_table_t get_doctor_id_information(const char *id);

	id_object = json_object_object_get(object,"id");
	if(id_object==NULL){
		printf("The json object no such doctor_id filed!\n");
		return;
	}
	id=json_object_get_string(id_object);
	printf("id:%s\n",id);
	doctor_information_table=get_doctor_id_information(id);
	if(!doctor_information_table.nrow){
		state=1;
	}

	client_object =create_client_json_object(DOCTOR_ID_INFORMATION_GET,state);
	if(client_object){
		if(doctor_information_table.nrow){
			add_doctor_information(client_object,&doctor_information_table);

			add_doctor_picture_information(client_object,id);
		}
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

	free_doctor_table(&doctor_information_table);
	return;
}

void handler_user_doctor_appointment(int client_fd ,json_object *object){

	int n=0;
	int state = user_doctor_appointment(object,&n);
	json_object *client_object =create_client_json_object(USER_DOCTOR_APPOINTMENT,state);
	if(client_object){
		json_object_object_add(client_object,"appointment-peoples",json_object_new_int(n));	
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

}

void handler_user_feature_data(int client_fd,json_object *object){


	int state = user_feature_data_store(object);
	json_object *client_object = create_client_json_object(PERSON_FEATURE_DATA,state);
	if(client_object){
	
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

	return;

}

void add_user_feature_data_information(json_object *object,feature_data_table_t *feature_data_table){

	int i;
	int j;
	int index=0;
	json_object *feature_data_array;

	feature_data_array=json_object_new_array();
	if(!feature_data_array){
		printf("Fail to json object new array!\n");
		return ;
	
	}
	for(i=0,index=feature_data_table->ncolum;i<feature_data_table->nrow;i++){
	
		json_object *object;
		object=json_object_new_object();
		for(j=0;j<feature_data_table->ncolum;j++){
			json_object_object_add(object,feature_data_table->result[j],json_object_new_string(feature_data_table->result[index++]));

		}
		json_object_array_add(feature_data_array,object);
	}
	
		json_object_object_add(object,"feature_data",feature_data_array);
		return;

}


void handler_chart_data(int client_fd,json_object *object){
	int state=0;
	json_object *client_object;
	feature_data_table_t feature_data_table;

	extern feature_data_table_t get_data_feature_data(json_object *object);
	feature_data_table=get_data_feature_data(object);
	if(!feature_data_table.nrow){
		state=1;
	
	}

	client_object =create_client_json_object(CHART_DATA ,state);
	if(client_object){
		if(feature_data_table.nrow){
			add_user_feature_data_information(client_object,&feature_data_table);
		
		}
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

	free_feature_data_table(&feature_data_table);
	return;



}

void handler_user_information_get(int client_fd,json_object *object)
{

	int state=0;
	json_object *client_object;
	doctor_information_table_t user_information_table;

	extern doctor_information_table_t get_all_user_information(void);
	user_information_table=get_all_user_information();
	if(!user_information_table.nrow){
		state=1;
	}
	client_object =create_client_json_object(USER_INFORMATION_GET,state);
	if(client_object){
		if(user_information_table.nrow){
			add_user_information(client_object,&user_information_table);
		
		}
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

	free_doctor_table(&user_information_table);
	return;

}

void handler_doctor_opinion(int client_fd,json_object *object)
{

	int state = doctor_opinion(object);
	json_object *client_object = create_client_json_object(DOCTOR_OPINION,state);
	if(client_object){
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}
	return;

}
void handler_doctor_message_get(int client_fd,json_object *object)
{

	int state=0;
	const char *username =NULL;
	json_object *username_object;
	json_object *client_object;
	doctor_information_table_t doctor_message_table;

	extern doctor_information_table_t get_all_doctor_message(const char *username);
	
	username_object=json_object_object_get(object,"username");
	if(username_object==NULL){
		printf("The json object no such username filed!\n");
		return;	
	}
	username=json_object_get_string(username_object);
	doctor_message_table=get_all_doctor_message(username);
	if(!doctor_message_table.nrow){
		state=1;
	}
	client_object =create_client_json_object(DOCTOR_MESSAGE,state);
	if(client_object){
		if(doctor_message_table.nrow){
			add_doctor_message(client_object,&doctor_message_table);
		
		}
		reply_client_result(client_fd,client_object);
		destory_client_json_object(client_object);
	}

	free_doctor_table(&doctor_message_table);
	return;

}


