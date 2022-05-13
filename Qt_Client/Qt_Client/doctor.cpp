#include "doctor.h"

doctor::doctor()
{

}

doctor::doctor(const QString &name, const QString &workTime, const QString &education, const QString &profession)
{
    this->name=name;
    this->workTime=workTime;
    this->education=education;
    this->profession=profession;

}

QString doctor::getName() const
{
    return name;
}

void doctor::setName(const QString &value)
{
    name = value;
}



QString doctor::getEducation() const
{
    return education;
}

void doctor::setEducation(const QString &value)
{
    education = value;
}

QString doctor::getWorkTime() const
{
    return workTime;
}

void doctor::setWorkTime(const QString &value)
{
    workTime = value;
}


QString doctor::getProfession() const
{
    return profession;
}

void doctor::setProfession(const QString &value)
{
    profession = value;
}

QString doctor::getId() const
{
    return id;
}

void doctor::setId(const QString &value)
{
    id = value;
}

QString doctor::getBriefIntroduce() const
{
    return briefIntroduce;
}

void doctor::setBriefIntroduce(const QString &value)
{
    briefIntroduce = value;
}
