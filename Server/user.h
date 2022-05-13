#ifndef _USER_HEAD_H
#define _USER_HEAD_H

typedef struct{
	char *username;
	char *password;
	char *telphone;
	char *fullname;
	char *id;
}user_register_t;

typedef struct{

	char *username;
	double blood_gluse;
	double blood_oxygen;
	double blood_presure;
	double heart_rate;
	double temperature;
	char *date;
}user_feature_data_t;


typedef struct{
	int nrow;
	int ncolum;
	char**result;
}feature_data_table_t;

#endif
