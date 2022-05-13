#ifndef USER_H
#define USER_H
#include <QString>


class user
{
public:
    user();
    user(QString &username);
    QString getUsername() const;
    void setUsername(const QString &value);
    
    QString getDiagnosticMessage() const;
    void setDiagnosticMessage(const QString &value);
    static QString diagnosticMessage; 
private:
    QString username;
    
};

#endif // USER_H
