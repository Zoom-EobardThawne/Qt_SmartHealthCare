#include <stdio.h>
#include <sqlite3.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "doctor.h"
#include "user.h"

pthread_mutex_t thread_lock = PTHREAD_MUTEX_INITIALIZER;

int verify_username_password(const char *username,const char *password)
{
	int ret;
	int ok = 1;
	char sql[1024];
	char **result;
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	sqlite3 *db_handler;

	pthread_mutex_lock(&thread_lock);

	ret = sqlite3_open("user.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open user.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&thread_lock);
		return -1;
	}

	//select * from user_info where username='farsight' and password='123456'
	sprintf(sql,"select * from user_info where username='%s' and password='%s'",username,password);	
	
	ret = sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret != SQLITE_OK){
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		pthread_mutex_unlock(&thread_lock);
		return -1;
	}
	
	if(row == 1){
		ok = 0;
	}

	sqlite3_free_table(result);

	sqlite3_close(db_handler);
	
	pthread_mutex_unlock(&thread_lock);

	return ok;
}

int verify_user_filed(const char *filed_name,const char *filed_value)
{
	int ret;
	int exist = 0;
	char sql[1024];
	char **result;
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	sqlite3 *db_handler;

	if(filed_name == NULL || filed_value == NULL){
		return -1;
	}

	pthread_mutex_lock(&thread_lock);

	ret = sqlite3_open("user.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open user.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&thread_lock);
		return -1;
	}

	sprintf(sql,"select * from user_info where %s='%s'",filed_name,filed_value);	
	
	ret = sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret != SQLITE_OK){
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		pthread_mutex_unlock(&thread_lock);
		sqlite3_close(db_handler); 
		return -1;
	}
	
	if(row == 1){
		exist = 1;
	}

	sqlite3_free_table(result);

	sqlite3_close(db_handler); 
	pthread_mutex_unlock(&thread_lock);

	return exist;
}


int check_user_register(user_register_t *user_register)
{
	if(user_register->username == NULL ||
	   user_register->password == NULL ||
	   user_register->telphone == NULL ||
	   user_register->fullname     == NULL ||
	   user_register->id       == NULL
	){
		return -1;
	}

	return 0;
}


int add_new_register_user(user_register_t *user_register)
{
	int ret = 0;
	int len = 0;	
	char *errmsg;
	char *sql = NULL;
	sqlite3 *db_handler;
	char *default_sql = "insert into user_info values(,,,,)";

	ret = check_user_register(user_register);
	if(ret){
		printf("Invalid user_register!\n");
		return -1;
	}

	len += strlen(user_register->username);
	len += strlen(user_register->password);
	len += strlen(user_register->telphone);
	len += strlen(user_register->fullname);
	len += strlen(user_register->id);
	len += strlen(default_sql);

	sql = malloc(len + 10);
	if(sql == NULL){
		printf("Fail to malloc!\n");
		return -1;
	}

	sprintf(sql,"insert into user_info values('%s','%s','%s','%s','%s')",
			user_register->username,\
			user_register->password,\
			user_register->telphone,\
			user_register->fullname,\
			user_register->id);	


	pthread_mutex_lock(&thread_lock);

	ret = sqlite3_open("user.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open user.db error:%s\n",sqlite3_errmsg(db_handler));
		ret = -1;
		goto err_1;
	}


	ret = sqlite3_exec(db_handler,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK){
		printf("sqlite3 exec %s error:%s\n",sql,errmsg);
		ret = -1;
		goto err_2;
	}

err_2:
	sqlite3_close(db_handler); 

err_1:
	pthread_mutex_unlock(&thread_lock);
	free(sql);

	return ret;
}

int verify_user_register(user_register_t *user_register)
{
	int err   = 0;
	int exist = 0;

	exist = verify_user_filed("username",user_register->username);
	if(exist){
		err = exist == -1 ? -1 : 1;
		return err;
	}

	exist = verify_user_filed("telphone",user_register->telphone);
	if(exist){
		err = exist == -1 ? -1 : 2;
		return err;
	}

	err = add_new_register_user(user_register);
	
	return err;
}


int verify_username_telphone_userid(const char *username,const char *telphone,const char *userid,char **password)
{

	int ret ;
	int ok =1;
	char sql[1024];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;


	pthread_mutex_lock(&thread_lock);
	ret = sqlite3_open("user.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten user.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&thread_lock);
		return -1;
	}

	sprintf(sql,"select password from user_info where username='%s' and telphone='%s' and id='%s'",username,telphone,userid);


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		pthread_mutex_unlock(&thread_lock);
		return -1;
	}

	if(row==1){//result :|password|123456
		ok =0 ;
		*password =malloc(strlen(result[1]));
		if(*password==NULL){
			perror("Fail to malloc");
			ok =-1;
		}else{

			strcpy(*password,result[1]);
			ok=0;
		}
	}

	sqlite3_free_table(result);

	sqlite3_close(db_handler); 
	pthread_mutex_unlock(&thread_lock);

	return ok;


}


int add_user_feature_data(user_feature_data_t  *user_feature_data)
{
	int ret = 0;
	int len = 0;	
	char *errmsg;
	char *sql = NULL;
	sqlite3 *db_handler;
	char *default_sql = "insert into user_data values('','','','','','','')";


	len += strlen(user_feature_data->username);
	len += sizeof(user_feature_data->blood_gluse );
	len += sizeof(user_feature_data->blood_oxygen);
	len += sizeof(user_feature_data->blood_presure);
	len += sizeof(user_feature_data->temperature);
	len += sizeof(user_feature_data->heart_rate);
	len += strlen(user_feature_data->date);
	len += strlen(default_sql);

	sql = malloc(len + 10);
	if(sql == NULL){
		printf("Fail to malloc!\n");
		return -1;
	}

	sprintf(sql,"insert into user_data values('%s','%f','%f','%f','%f',%f,'%s')",
			user_feature_data->username,\
			user_feature_data->blood_gluse,\
			user_feature_data->blood_oxygen,\
			user_feature_data->blood_presure,\
			user_feature_data->temperature,\
			user_feature_data->heart_rate,\
			user_feature_data->date);	

	pthread_mutex_lock(&thread_lock);

	ret = sqlite3_open("user.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open user.db error:%s\n",sqlite3_errmsg(db_handler));
		ret = -1;
		goto err_1;
	}


	ret = sqlite3_exec(db_handler,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK){
		printf("sqlite3 exec %s error:%s\n",sql,errmsg);
		ret = -1;
		goto err_2;
	}

err_2:
	sqlite3_close(db_handler); 

err_1:
	pthread_mutex_unlock(&thread_lock);
	free(sql);

	return ret;
}

 
feature_data_table_t query_user_feature_data(const char *username,const char *start_date,const char *end_date)
{

	int ret ;
	char sql[4096];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;
	feature_data_table_t feature_data_table={0};


	pthread_mutex_lock(&thread_lock);
	ret = sqlite3_open("user.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten user.db error:%s\n",sqlite3_errmsg(db_handler));
	
		goto err;
	}

	sprintf(sql,"select * from user_data where username ='%s' and date>='%s' and date<='%s'",username,start_date,end_date);


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		
		goto err;
	}
err:
	sqlite3_close(db_handler);
	pthread_mutex_unlock(&thread_lock);


	feature_data_table.nrow=row;
	feature_data_table.ncolum=column;
	feature_data_table.result=result;
	printf("row:%d\ncolumn:%d\n",row,column);

	return feature_data_table;


}


doctor_information_table_t get_all_user_information(void)
{

	int ret ;
	int ok =1;
	char sql[1024];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;
	doctor_information_table_t user_information_table={0};


	pthread_mutex_lock(&thread_lock);
	ret = sqlite3_open("user.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten user.db error:%s\n",sqlite3_errmsg(db_handler));
	
		goto err;
	}

	sprintf(sql,"select username  from user_info");


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		
		goto err;
	}
err:
	sqlite3_close(db_handler);
	pthread_mutex_unlock(&thread_lock);


	user_information_table.nrow=row;
	user_information_table.ncolum=column;
	user_information_table.result=result;

	return user_information_table;

}


