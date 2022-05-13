#include <stdio.h>
#include <sys/types.h>	       /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <json/json.h>
#include <string.h>
#include "doctor.h"

int doctor_login(json_object *object)
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


	ok = verify_doctoe_login(username,password);
	
	return ok;
}


void  add_doctor_register_information(json_object *object,char *filed_name,char **address)
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

void base64_to_picture(const char *base64_data,const char *filename){

	FILE *fp;
	char command[1024];
	fp = fopen(filename,"w");
	if(!fp){
		perror("Fail to fopen");
		return;
	}
	fputs(base64_data,fp);
	fclose(fp);
	snprintf(command,sizeof(command),"base64 -d %s > doctor_picture/%s.jpg",filename,filename);
	system(command);
	remove(filename);
	return;

}

void add_doctor_register_picture(json_object *object,char *filed_name,char *filedname){

	const char *filed_value;
	json_object *filed_object;
	filed_object =json_object_object_get(object,filed_name);
	if(filed_object==NULL){
	
		printf("The json object no such %s filed!\n",filed_name);
		return;
	}
	filed_value=json_object_get_string(filed_object);
	base64_to_picture(filed_value,filedname);
	return;

}


void free_doctor_register(doctor_register_t *doctor_register)
{
	if(doctor_register->username){
		free(doctor_register->username);
	}

	if(doctor_register->password){
		free(doctor_register->password);
	}

	if(doctor_register->telphone){
		free(doctor_register->telphone);
	}

	if(doctor_register->fullname){
		free(doctor_register->fullname);
	}

	if(doctor_register->id){
		free(doctor_register->id);
	}
	if(doctor_register->worktime){
		free(doctor_register->worktime);
	}
	if(doctor_register->major){
		free(doctor_register->major);
	}
	if(doctor_register->education){
		free(doctor_register->education);
	}
	if(doctor_register->briefIntroduction){
		free(doctor_register->briefIntroduction);
	}


	return;
}

void free_doctor_opinion(doctor_opinion_t *doctor_opinion)
{
	if(doctor_opinion->username){
		free(doctor_opinion->username);
	}

	if(doctor_opinion->doctorname){
		free(doctor_opinion->doctorname);
	}

	if(doctor_opinion->opinionTxt){
		free(doctor_opinion->opinionTxt);
	}
	return;
}


int doctor_register(json_object *object)
{
	int ret;
	int ok = 0;
	doctor_register_t doctor_register = {0};

	add_doctor_register_information(object,"username",&(doctor_register.username));
	add_doctor_register_information(object,"password",&(doctor_register.password));
	add_doctor_register_information(object,"telphone",&(doctor_register.telphone));
	add_doctor_register_information(object,"fullname",&(doctor_register.fullname));
	add_doctor_register_information(object,"id",&(doctor_register.id));
	add_doctor_register_information(object,"worktime",&(doctor_register.worktime));
	add_doctor_register_information(object,"major",&(doctor_register.major));
 	add_doctor_register_information(object,"education",&(doctor_register.education));
	add_doctor_register_information(object,"briefIntroduction",&(doctor_register.briefIntroduction));
	ok = verify_doctor_register(&doctor_register);

	if(ok==0){
		add_doctor_register_picture(object,"picture",doctor_register.id);
	
	}
	free_doctor_register(&doctor_register);

	return ok;

}

int doctor_get_password(json_object *object ,char **password)
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
	

	ok =verify_username_telphone_doctorid(username,telphone,userid,password);
	return ok;
	
}



int user_doctor_appointment(json_object *object,int *n){


	int ok =0;
	const char *username =NULL;
	const char *doctorid =NULL;
	const char *date =NULL;
	json_object *username_object;
	json_object *doctorid_object;
	json_object *date_object;

	username_object = json_object_object_get(object,"username");
	if(username_object==NULL){
	
		printf("The json object no such username filed!\n");
		return -1;
	}
	username=json_object_get_string(username_object);

	doctorid_object=json_object_object_get(object,"doctorid");
	if(doctorid_object==NULL){
	
		printf("The json object no such doctorid filed!\n");
		return -1;
	}
	doctorid =json_object_get_string(doctorid_object);

	date_object=json_object_object_get(object,"date");
	if(date_object==NULL){
	
		printf("The json object no such date filed!\n");
		return -1;
	}
	date =json_object_get_string(date_object);

	ok=add_user_doctor_appointment(username,doctorid,date,n);
	return ok;

}


int doctor_opinion(json_object *object)
{
	int ret;
	int ok = 0;
	doctor_opinion_t doctor_opinion = {0};


	add_doctor_register_information(object,"username",&(doctor_opinion.username));
	add_doctor_register_information(object,"doctorName",&(doctor_opinion.doctorname));
	add_doctor_register_information(object,"doctorOpinion",&(doctor_opinion.opinionTxt));
	
	ok = verify_doctor_opinion(&doctor_opinion);
	free_doctor_opinion(&doctor_opinion);

	return ok;

}


 
