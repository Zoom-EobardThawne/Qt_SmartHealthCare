#include <stdio.h>
#include <sqlite3.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "doctor.h"

pthread_mutex_t doctor_thread_lock = PTHREAD_MUTEX_INITIALIZER;

int verify_doctoe_login(const char *username,const char *password)
{
	int ret;
	int ok = 1;
	char sql[1024];
	char **result;
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	sqlite3 *db_handler;

	pthread_mutex_lock(&doctor_thread_lock);

	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open doctor.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&doctor_thread_lock);
		return -1;
	}

	sprintf(sql,"select * from doctor_info where username='%s' and password='%s'",username,password);

	ret = sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret != SQLITE_OK){
				printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
				pthread_mutex_unlock(&doctor_thread_lock);
				return -1;
	}

		
	if(row == 1){
		ok = 0;
	}

	sqlite3_free_table(result);

	sqlite3_close(db_handler);
	
	pthread_mutex_unlock(&doctor_thread_lock);

	return ok;
}

int verify_doctor_filed(const char *filed_name,const char *filed_value)
{
	int ret;
	int exist = 0;
	char sql[1024];
	char **result=NULL;
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	sqlite3 *db_handler;

	if(filed_name == NULL || filed_value == NULL){
		return -1;
	}

	pthread_mutex_lock(&doctor_thread_lock);

	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open doctor.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&doctor_thread_lock);
		return -1;
	}

	sprintf(sql,"select * from doctor_info where %s='%s'",filed_name,filed_value);	
	
	ret = sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret != SQLITE_OK){
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		pthread_mutex_unlock(&doctor_thread_lock);
		sqlite3_close(db_handler); 
		return -1;
	}
	
	if(row == 1){
		exist = 1;
	}
	if(result){
	
		sqlite3_free_table(result);
	}


	sqlite3_close(db_handler); 
	pthread_mutex_unlock(&doctor_thread_lock);

	return exist;
}


int check_doctor_register(doctor_register_t *doctor_register)
{
	if(doctor_register->username == NULL ||
	   doctor_register->password == NULL ||
	   doctor_register->telphone == NULL ||
	   doctor_register->fullname == NULL ||
	   doctor_register->id       == NULL ||
	   doctor_register->worktime == NULL ||
	   doctor_register->education== NULL ||
	   doctor_register->major    == NULL ||
	   doctor_register->briefIntroduction==NULL 

	){
		return -1;
	}

	return 0;
}


int add_new_register_doctor(doctor_register_t *doctor_register)
{
	int ret = 0;
	int len = 0;	
	char *errmsg;
	char *sql = NULL;
	sqlite3 *db_handler;
	char *default_sql = "insert into doctor_info values('','','','','','','','','')";

	ret = check_user_register(doctor_register);
	if(ret){
		printf("Invalid doctor_register!\n");
		return -1;
	}

	len += strlen(doctor_register->username);
	len += strlen(doctor_register->password);
	len += strlen(doctor_register->telphone);
	len += strlen(doctor_register->fullname);
	len += strlen(doctor_register->id);
	len += strlen(doctor_register->worktime);
	len += strlen(doctor_register->major);
	len += strlen(doctor_register->education);
	len += strlen(doctor_register->briefIntroduction);
	len += strlen(default_sql);

	sql = malloc(len + 10);
	if(sql == NULL){
		printf("Fail to malloc!\n");
		return -1;
	}

	sprintf(sql,"insert into doctor_info values('%s','%s','%s','%s','%s','%s','%s','%s','%s')",
			doctor_register->username,\
			doctor_register->password,\
			doctor_register->telphone,\
			doctor_register->fullname,\
			doctor_register->id,\
			doctor_register->worktime,\
			doctor_register->education,\
			doctor_register->major,\
			doctor_register->briefIntroduction);


	pthread_mutex_lock(&doctor_thread_lock);

	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open doctor.db error:%s\n",sqlite3_errmsg(db_handler));
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
	pthread_mutex_unlock(&doctor_thread_lock);
	free(sql);

	return ret;
}

int verify_doctor_register(doctor_register_t *doctor_register)
{
	int err   = 0;
	int exist = 0;

	exist = verify_doctor_filed("username",doctor_register->username);
	if(exist){
		err = exist == -1 ? -1 : 1;
		return err;
	}

	exist = verify_doctor_filed("telphone",doctor_register->telphone);
	if(exist){
		err = exist == -1 ? -1 : 2;
		return err;
	}

	err = add_new_register_doctor(doctor_register);
	
	return err;
}


int verify_username_telphone_doctorid(const char *username,const char *telphone,const char *userid,char **password)
{

	int ret ;
	int ok =1;
	char sql[1024];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;


	pthread_mutex_lock(&doctor_thread_lock);
	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten doctor.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&doctor_thread_lock);
		return -1;
	}

	sprintf(sql,"select password from doctor_info where username='%s' and telphone='%s' and id='%s'",username,telphone,userid);


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		pthread_mutex_unlock(&doctor_thread_lock);
		return -1;
	}

	if(row==1){//result :|password|123456
		ok =0 ;
		*password =malloc(strlen(result[1])+1);
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
	pthread_mutex_unlock(&doctor_thread_lock);

	return ok;

}

 

doctor_information_table_t get_all_doctor_information(void)
{

	int ret ;
	int ok =1;
	char sql[1024];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;
	doctor_information_table_t doctor_information_table={0};


	pthread_mutex_lock(&doctor_thread_lock);
	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten doctor.db error:%s\n",sqlite3_errmsg(db_handler));
	
		goto err;
	}

	sprintf(sql,"select fullname,worktime,major,education,id  from doctor_info");


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		
		goto err;
	}
err:
	sqlite3_close(db_handler);
	pthread_mutex_unlock(&doctor_thread_lock);


	doctor_information_table.nrow=row;
	doctor_information_table.ncolum=column;
	doctor_information_table.result=result;

	return doctor_information_table;


}





doctor_information_table_t get_doctor_id_information(const char *id)
{

	int ret ;
	char sql[1024];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;
	doctor_information_table_t doctor_information_table={0};


	pthread_mutex_lock(&doctor_thread_lock);
	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten doctor.db error:%s\n",sqlite3_errmsg(db_handler));
	
		goto err;
	}

	sprintf(sql,"select fullname,worktime,major,education,briefIntroduction  from doctor_info where id ='%s'",id);


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		
		goto err;
	}
err:
	sqlite3_close(db_handler);
	pthread_mutex_unlock(&doctor_thread_lock);


	doctor_information_table.nrow=row;
	doctor_information_table.ncolum=column;
	doctor_information_table.result=result;

	return doctor_information_table;


}



int verify_user_doctor_appointment(const char *username,const char *doctorid,const char *date,int *n)
{
	int ret;
	int exist = 0;
	char sql[4096];
	char **result=NULL;
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	sqlite3 *db_handler;


	pthread_mutex_lock(&doctor_thread_lock);

	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open doctor.db error:%s\n",sqlite3_errmsg(db_handler));
		pthread_mutex_unlock(&doctor_thread_lock);
		return -1;
	}

	sprintf(sql,"select * from doctor_appointment where username='%s' and doctorid='%s' and date='%s'"\
			,username,doctorid,date);	
	
	ret = sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret != SQLITE_OK){
		printf("Fail to sqlite3_get_table0,error:%s\n",errmsg);
		pthread_mutex_unlock(&doctor_thread_lock);
		sqlite3_close(db_handler); 
		return -1;
	}
	
	if(row == 1){
		exist =1;
	}
	if(result){
	
		sqlite3_free_table(result);
	}
 
		sprintf(sql,"select * from doctor_appointment where doctorid='%s' and date='%s'",doctorid,date);	
	
		ret = sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
		if(ret != SQLITE_OK){
			printf("Fail to sqlite3_get_table1,error:%s\n",errmsg);
			pthread_mutex_unlock(&doctor_thread_lock);
			sqlite3_close(db_handler); 
			return -1;
		}
	*n =row;
	
	if(result){
	
		sqlite3_free_table(result);
	}
 
	sqlite3_close(db_handler); 
	pthread_mutex_unlock(&doctor_thread_lock);

	return exist;
}





int add_user_doctor_appointment(const char *username,const char *doctorid,const char *date,int *n){

	int ret =0;
	int len =0;
	char *errmsg;
	char *sql=NULL;
	sqlite3 *db_handler;
	char *default_sql="insert into doctor_appointment values('','','')";
	ret =verify_user_doctor_appointment(username,doctorid,date,n);
	if(ret){
		printf("already appointment!\n");
		return ret;
	}

	if(*n>=5){
		return 2;
	}

	len += strlen(username);
	len += strlen(doctorid);
	len += strlen(date);
	len += strlen(default_sql);

	sql =malloc(len+10);
	if(sql == NULL){
	
		printf("Fail to malloc!\n");
		return -1;
	}

	sprintf(sql,"insert into doctor_appointment values('%s','%s','%s')",username,doctorid,date);

	pthread_mutex_lock(&doctor_thread_lock);

	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open doctor.db error:%s\n",sqlite3_errmsg(db_handler));
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
	pthread_mutex_unlock(&doctor_thread_lock);
	free(sql);

	return ret;
}


int verify_doctor_opinion(doctor_opinion_t *doctor_opinion)
{
	int ret = 0;
	int len = 0;	
	char *sql = NULL;
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	sqlite3 *db_handler;

	char *default_sql = "insert into doctor_info values('',''.'')";


	len += strlen(doctor_opinion->username);
	len += strlen(doctor_opinion->doctorname);
	len += strlen(doctor_opinion->opinionTxt);
	len += strlen(default_sql);

	sql = malloc(len + 10);
	if(sql == NULL){
		printf("Fail to malloc!\n");
		return -1;
	}

	sprintf(sql,"insert into doctor_opinion values('%s','%s','%s')",
			doctor_opinion->username,\
			doctor_opinion->doctorname,\
			doctor_opinion->opinionTxt);
			

	pthread_mutex_lock(&doctor_thread_lock);

	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret != SQLITE_OK){
		printf("sqlite3 open doctor.db error:%s\n",sqlite3_errmsg(db_handler));
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
	pthread_mutex_unlock(&doctor_thread_lock);
	free(sql);

	return ret;

}

doctor_information_table_t get_all_doctor_message(const char *username)
{

	int ret ;
	int ok =1;
	char sql[1024];
	char **result;
	int row =0;
	int column =0;
	char *errmsg =NULL;
	sqlite3 *db_handler;
	doctor_information_table_t doctor_message_table={0};


	pthread_mutex_lock(&doctor_thread_lock);
	ret = sqlite3_open("doctor.db",&db_handler);
	if(ret !=SQLITE_OK){
		printf("sqlite3 opten doctor.db error:%s\n",sqlite3_errmsg(db_handler));
	
		goto err;
	}

	sprintf(sql,"select * from doctor_opinion where username='%s'",username);


	ret =sqlite3_get_table(db_handler,sql,&result,&row,&column,&errmsg);
	if(ret !=SQLITE_OK){
	
		printf("Fail to sqlite3_get_table,error:%s\n",errmsg);
		
		goto err;
	}
err:
	sqlite3_close(db_handler);
	pthread_mutex_unlock(&doctor_thread_lock);


	doctor_message_table.nrow=row;
	doctor_message_table.ncolum=column;
	doctor_message_table.result=result;

	return doctor_message_table;


}

 
