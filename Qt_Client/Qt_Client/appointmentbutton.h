#ifndef APPOINTMENTBUTTON_H
#define APPOINTMENTBUTTON_H

#include <QPushButton>
#include "doctor.h"
#include "user.h"

class AppointmentButton : public QPushButton
{
    Q_OBJECT
public:
    explicit AppointmentButton(QWidget *parent = nullptr);

    doctor getDoctor() const;
    void setDoctor(const doctor &value);

    user getUser() const;
    void setUser(const user &value);
    
signals:
    
public slots:
    
private:
    doctor Doctor;
    user User;

};

#endif // APPOINTMENTBUTTON_H
