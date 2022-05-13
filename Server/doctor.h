#ifndef _DOCTOR_HEAD_H
#define _DOCTOR_HEAD_H

typedef struct{
	char *username;
	char *password;
	char *telphone;
	char *fullname;
	char *id;
	char *worktime;
	char *major;
	char *education;
	char *briefIntroduction;
}doctor_register_t;

typedef struct{

	int nrow;
	char **result;
	int ncolum;

}doctor_information_table_t;

typedef struct{

	char *username;
	char *doctorname;
	char *opinionTxt;
}doctor_opinion_t;

#endif
