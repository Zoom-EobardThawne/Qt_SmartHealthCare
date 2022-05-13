#ifndef _HANDLER_CLIENT_HEAD_
#define _HANDLER_CLIENT_HEAD_

#define USER_REGISTER  0
#define USER_LOGIN      1
#define USER_GET_PASSWORD 2
#define DOCTOR_REGISTER 3
#define DOCTOR_INFORMATION_GET 4 
#define DOCTOR_ID_INFORMATION_GET 5
#define DOCTOR_LOGIN 6
#define DOCTOR_GET_PASSWORD 7
#define USER_DOCTOR_APPOINTMENT 8
#define PERSON_FEATURE_DATA 9
#define CHART_DATA 10
#define USER_INFORMATION_GET 11
#define DOCTOR_OPINION 12
#define DOCTOR_MESSAGE 13
#include <json/json.h>

extern void handler_user_register(int client_fd,json_object *object);
extern void handler_user_login(int client_fd,json_object *object);
extern void handler_user_get_password(int client_fd,json_object *object);
extern void handler_doctor_register(int client_fd,json_object *object);
extern void handler_doctor_information_get(int client_fd,json_object *object);
extern void handler_doctor_id_information_get(int client_fd,json_object *object);
extern void handler_doctor_login(int client_fd,json_object *object);
extern void handler_doctor_get_password(int client_fd,json_object *object);
extern void handler_user_doctor_appointment(int client_fd,json_object *object);
extern void handler_user_feature_data(int client_fd,json_object *object);
extern void handler_chart_data(int client_fd,json_object *object);
extern void handler_user_information_get(int cllient_fd,json_object *object);
extern void handler_doctor_opinion(int client_fd,json_object *object);
extern void handler_doctor_message_get(int client_fd ,json_object *object);
#endif
