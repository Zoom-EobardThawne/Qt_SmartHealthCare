#ifndef DOCTOR_H
#define DOCTOR_H
#include <QString>

class doctor
{
public:
    doctor();
    doctor(const QString &name,const QString &workTime,const QString &education,const QString &profession);


    QString getName() const;
    void setName(const QString &value);

    QString getWorkTime() const;
    void setWorkTime(const QString &value);

    QString getEducation() const;
    void setEducation(const QString &value);

    QString getProfession() const;
    void setProfession(const QString &value);

    QString getId() const;
    void setId(const QString &value);

    QString getBriefIntroduce() const;
    void setBriefIntroduce(const QString &value);
    
private:
    QString id;
    QString name;
    QString workTime;
    QString education;
    QString profession;
    QString briefIntroduce;
   

};

#endif // DOCTOR_H
