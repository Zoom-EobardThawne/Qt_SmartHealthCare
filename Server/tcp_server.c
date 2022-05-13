#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <json/json.h>

#define SUCCESS_STATE 0
#define FAILE_STATE  1

/**客户端返回的结果**/
void reply_client_result(int client_fd,int function_id,int state)
{	
	int ret;
	const char *json_string;			//json字符串
	json_object *object;

	object = json_object_new_object();
	if(object == NULL){
		printf("Fail to json object new object!\n");
		return;
	}
	json_object_object_add(object,"fuction_id",json_object_new_int(function_id));
	json_object_object_add(object,"state",json_object_new_int(state));
	json_string = json_object_to_json_string(object);
	if(json_string == NULL){
		json_object_put(object);
		printf("Fail to json_object_to_json_string!\n");
		return;
	}

	ret= send(client_fd,json_string,strlen(json_string),0);
	if(ret < 0){
		perror("Fail to send!");
	}
	printf("reply client:%s\n",json_string);
	json_object_put(object);

	return;

}

/**对接收的json解析功能号**/
void parse_json_data(int client_fd,const char *json_string)
{
	int function_id;						//功能号
	json_object *object;
	json_object *function_id_object;		//功能号对象

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
	/**获取功能号**/
	function_id = json_object_get_int(function_id_object);
	printf("function_id : %d\n",function_id);

	if(function_id == 1){
		int state = user_login(object);
		reply_client_result(client_fd,function_id,state);
	}

	json_object_put(function_id_object);

error_1:	
	json_object_put(object);

	return;
}


/**接收客户端的数据进行处理**/ 
void *do_client(void *arg)
{
	int ret;
	char buf[1024];
	int client_fd = *((int *)arg); //arg记录client_fd地址，强转类型读取内容

	while(1){
		printf("recv client_fd:%d......\n",client_fd);
		ret = recv(client_fd, buf, sizeof(buf), 0); 	
		//recv函数参数含义 （从client_fd套接字接收数据，存放数据的地址，数据长度，标志位）
		if (ret <= 0)
		{
			perror("Fail to recv or Link break");
			break;
		}
		else
		{
			buf[ret] = '\0';
			printf("receiev: %d bytes, message: %s\n", ret, buf);
			parse_json_data(client_fd, buf);//调用脚本解析函数
		}
	}
	close(client_fd);
}

int main(void)
{
	int fd;			//file descriptor
	int ret;		//返回值 成功0 失败-1
	int client_fd; 	//客户端文件描述符
	pthread_t tid;  //线程ID
	struct sockaddr_in server_addr;		//结构体指定服务端IP和端口
	
	/**创建套接字**/
	fd = socket(AF_INET,SOCK_STREAM,0);  //创建一个监听套接字
	if(fd < 0){
		perror("Fail to socket");		//打印错误信息
		return -1;						//错误返回-1
	}
	printf("fd = %d\n",fd);				//打印文件描述符数字

	/**填充服务器IP和端口号**/
	server_addr.sin_family = AF_INET;			//地址类型：IPv4 AF_INET
	server_addr.sin_port   = htons(8888);		//端口号  用htons()函数把主机字节序转成网络字节序
	server_addr.sin_addr.s_addr = inet_addr("172.26.38.112");		//inet_addr函数将IP地址字符串转换成网络字节序

	/**绑定地址**/
	ret = bind(fd,(const struct sockaddr *)&server_addr,sizeof(server_addr));	//bind函数给套接字进行地址绑定
	if(ret < 0){
		perror("Fail to bind");
		return -1;
	}

	/**设置服务器套接字为监听模式**/
	ret = listen(fd,128);
	if(ret < 0){
		perror("Fail to listen");
		return -1;
	}
	printf("listen ......\n");

	/**循环接受客户端请求**/
	while(1){

		client_fd = accept(fd,NULL,NULL);
		if(client_fd < 0){
			perror("Fail to accept");
			return -1;
		}
		printf("client_fd : %d\n",client_fd);

		/**创建线程用来处理客户端发来的数据**/
		pthread_create(&tid, NULL, do_client, &client_fd);//最后一个参数传送client_fd地址
		pthread_detach(tid); 							 //将线程标记为分离式
	}

	return 0;
}
