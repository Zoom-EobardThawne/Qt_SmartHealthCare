#ifndef USERVERIFY_H
#define USERVERIFY_H

#include <QObject>
#include <QTcpSocket>

#define LOGIN_FUNCTION_ID 1
#define REGISTER_FUNCTION_ID 0
#define PASSWORD_FUNCTION_ID 2
#define LOGIN_DOCTOR_FUNCTION 6
#define PASSWORD_DOCTOR_FUNCTION 7

class Userverify : public QObject
{
    Q_OBJECT
public:
    explicit Userverify(QObject *parent = nullptr);

signals:
    void loginState(int state);
    void registerState(int state);
    void getPasswordState(int state,const QString &password);

public slots:
    void readSocketData(void);
    void verifyUserNamePassword(const QString &username, const QString &password);
    void verifyDoctorNamePassword(const QString &username, const QString &password);
    void verifyRegisterInformation(const QStringList &registerList);
    void verifyUserGetPassword(const QString &username,const QString &telphone,const QString &ID);
    void verifyDoctorGetPassword(const QString &username,const QString &telphone,const QString &ID);

private:
    QTcpSocket tcpSocket;

};
#endif // USERVERIFY_H
