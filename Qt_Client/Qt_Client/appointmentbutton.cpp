#include "appointmentbutton.h"

AppointmentButton::AppointmentButton(QWidget *parent) : QPushButton(parent)
{

}

doctor AppointmentButton::getDoctor() const
{
    return Doctor;
}

void AppointmentButton::setDoctor(const doctor &value)
{
    Doctor = value;
}

user AppointmentButton::getUser() const
{
    return User;
}

void AppointmentButton::setUser(const user &value)
{
    User = value;
}
