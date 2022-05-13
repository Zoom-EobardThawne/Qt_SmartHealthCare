#include "user.h"

QString user::diagnosticMessage;
user::user()
{
    
}

user::user(QString &username)
{
    this->username=username;
    //this->diagnosticMessage=diagnosticMessage;
    
}

QString user::getUsername() const
{
    return username;
}

void user::setUsername(const QString &value)
{
    username = value;
}


