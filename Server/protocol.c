#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>       /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PROTOCOL_HEAD_SIZE 4

int recv_protocol_head(int sockfd)
{
	int n;
 	int count =0;
	unsigned int dataLen=0;
	while(1){
		n =recv(sockfd,(char *)&dataLen+count,PROTOCOL_HEAD_SIZE-count,0);
		if(n<=0){
		
			perror("Fail to recv");
			break;
		}
		count +=n;
		if(count == PROTOCOL_HEAD_SIZE){
			break;
		}
	}
	return dataLen;
}

void free_protocol_data(char *addr)
{
	free(addr);
}

char  *recv_protocol_data(int sockfd)
{
	int n;
	int ret;
	unsigned int dataLen;
	char *buf;
	unsigned int count =0;

	dataLen = recv_protocol_head(sockfd);
	printf("dataLen= %d\n",dataLen);

	if(!dataLen){
		return NULL; 
	}

	buf = (char *)malloc(dataLen+1);
	if(!buf){
	
		perror("Fail to malloc");
			return NULL;
	}

	while(1){
		n =recv(sockfd,buf + count,dataLen - count,0);
		if(n<=0){
		
			perror("Fail to recv");
			break;
		}
		count += n;
		if(count == dataLen){
			break;
		}
	}
	buf[dataLen]='\0';
	if(count<dataLen){
	
		free(buf);
		return NULL;
	}
	
	return buf;
	
}
