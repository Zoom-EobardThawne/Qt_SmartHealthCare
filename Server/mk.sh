gcc user.c db.c handler_client.c db_doctor.c doctor.c protocol.c tcp_thread_server.c -o server -I /root/json-c-0.10/install/include -L /root/json-c-0.10/install/lib -ljson -lpthread -lsqlite3
