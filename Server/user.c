#include <stdio.h>
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <json/json.h>
#include <string.h>
#include "user.h"

int user_login(json_object *object)
{
	int ok = 0;
	const char *username = NULL;
	const char *password = NULL;
	json_object *username_object;
	json_object *password_object;

	username_object = json_object_object_get(object,"username");
	if(username_object == NULL){
		printf("The json object no such username filed!\n");
		return -1;
	}

	username = json_object_get_string(username_object);
	printf("username : %s\n",username);

	password_object = json_object_object_get(object,"password");
	if(password_object  == NULL){
		printf("The json object no such password filed!\n");
		return -1;
	}
	password = json_object_get_string(password_object);
	printf("password : %s\n",password);


	ok = verify_username_password(username,password);
	
	return ok;
}


void  add_user_register_information(json_object *object,char *filed_name,char **address)
{
	const char *filed_value;
	json_object *filed_object;

	filed_object = json_object_object_get(object,filed_name);
	if(filed_object == NULL){
		printf("The json object no such %s filed!\n",filed_name);
		return;
	}	
	filed_value = json_object_get_string(filed_object);

	*address = malloc(strlen(filed_value) + 1);
	if(*address == NULL){
		printf("Fail to malloc!\n");
		return;
	}
	strcpy(*address,filed_value);

	return;
}



void free_user_register(user_register_t *user_register)
{
	if(user_register->username){
		free(user_register->username);
	}

	if(user_register->password){
		free(user_register->password);
	}

	if(user_register->telphone){
		free(user_register->telphone);
	}

	if(user_register->fullname){
		free(user_register->fullname);
	}

	if(user_register->id){
		free(user_register->id);
	}

	return;
}

void free_user_feature_data(user_feature_data_t *user_feature_data)
{
	if(user_feature_data->username){
		free(user_feature_data->username);
	}

	if(user_feature_data->date){
		free(user_feature_data->date);
	}
}




int user_register(json_object *object)
{
	int ret;
	int ok = 0;
	user_register_t user_register = {0};

	add_user_register_information(object,"username",&(user_register.username));
	add_user_register_information(object,"password",&(user_register.password));
	add_user_register_information(object,"telphone",&(user_register.telphone));
	add_user_register_information(object,"fullname",&(user_register.fullname));
	add_user_register_information(object,"id",&(user_register.id));

	ok = verify_user_register(&user_register);

	free_user_register(&user_register);

	return ok;

}

int user_get_password(json_object *object ,char **password)
{
	int ok =0;
	const char *username =NULL;
	const char *telphone= NULL;
	const char *userid = NULL;
	json_object *username_object;
	json_object *telphone_object;
	json_object *userid_object;

	username_object = json_object_object_get(object,"username");
	if(username_object==NULL){
		printf("The json object no such username filed!\n");
		return -1;
	}

	username=json_object_get_string(username_object);
	printf("username: %s\n",username);


	telphone_object = json_object_object_get(object,"telphone");
	if(telphone_object==NULL){
		printf("The json object no such telphone filed!\n");
		return -1;
	}
	telphone =json_object_get_string(telphone_object);
	printf("telphone: %s\n",telphone);

	userid_object =json_object_object_get(object,"id");
	if(userid_object==NULL){
		printf("The json object no such userid filed!\n");
		return -1;
	}
	userid = json_object_get_string(userid_object);
	printf("userid: %s\n",userid);
	

	ok =verify_username_telphone_userid(username,telphone,userid,password);
	return ok;
	
}

int user_feature_data_store(json_object *object)
{
	int ret;
	int ok = 0;
	user_feature_data_t user_feature_data = {0};

	add_user_register_information(object,"username",&(user_feature_data.username));
	add_user_register_information(object,"date",&(user_feature_data.date));
	json_object *blood_gluse_object;
	json_object *blood_oxygen_object;
	json_object *blood_presure_object;
	json_object *heart_rate_object;
	json_object *temperature_object;

	blood_gluse_object = json_object_object_get(object,"blood_gluse");
	if(blood_gluse_object==NULL){
		printf("The json object no such blood_gluse filed!\n");
		return -1;
	}
	user_feature_data.blood_gluse=json_object_get_double(blood_gluse_object);
	printf("blood_gluse: %f\n",user_feature_data.blood_gluse);
	
	blood_oxygen_object = json_object_object_get(object,"blood_oxygen");
	if(blood_oxygen_object==NULL){
		printf("The json object no such blood_oxygen filed!\n");
		return -1;
	}
	user_feature_data.blood_oxygen=json_object_get_double(blood_oxygen_object);
	printf("blood_oxygen: %f\n",user_feature_data.blood_oxygen);

	blood_presure_object = json_object_object_get(object,"blood_gluse");
	if(blood_presure_object==NULL){
		printf("The json object no such blood_presure filed!\n");
		return -1;
	}
	user_feature_data.blood_presure=json_object_get_double(blood_presure_object);
	printf("blood_presure: %f\n",user_feature_data.blood_presure);


	heart_rate_object = json_object_object_get(object,"heart_rate");
	if(blood_oxygen_object==NULL){
		printf("The json object no such heart_rate filed!\n");
		return -1;
	}
	user_feature_data.heart_rate=json_object_get_double(heart_rate_object);
	printf("heart_rate: %f\n",user_feature_data.heart_rate);

	temperature_object = json_object_object_get(object,"temperature");
	if(temperature_object==NULL){
		printf("The json object no such temperature filed!\n");
		return -1;
	}
	user_feature_data.temperature=json_object_get_double(temperature_object);
	printf("temperature: %f\n",user_feature_data.temperature);

	
	ok = add_user_feature_data(&user_feature_data);

	free_user_feature_data(&user_feature_data);

	return ok;

}

feature_data_table_t get_data_feature_data(json_object *object)
{
	const char *username = NULL;
	const char *start_date = NULL;
	const char *end_date =NULL;
	json_object *username_object;
	json_object *start_date_object;
	json_object *end_date_object;

	feature_data_table_t data_table={0};

	username_object = json_object_object_get(object,"username");
	if(username_object == NULL){
		printf("The json object no such username filed!\n");
		return data_table;
	}
	extern feature_data_table_t  query_user_feature_data(const char *username,const char *start_date,const char *end_date);

	username = json_object_get_string(username_object);
	printf("username : %s\n",username);

	start_date_object = json_object_object_get(object,"startDate");
	if(start_date_object  == NULL){
		printf("The json object no such startDate filed!\n");
		return data_table;
	}

	start_date = json_object_get_string(start_date_object);
	printf("start_date : %s\n",start_date);

	end_date_object = json_object_object_get(object,"endDate");
	if(end_date_object  == NULL){
		printf("The json object no such endDate filed!\n");
		return data_table;
	}

	end_date = json_object_get_string(end_date_object);
	printf("end_date : %s\n",end_date);

			
	return  query_user_feature_data(username,start_date,end_date);

}

