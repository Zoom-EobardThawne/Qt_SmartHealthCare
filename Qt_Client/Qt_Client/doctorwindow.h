#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QMainWindow>
#include "doctor.h"
#include "doctorinformationget.h"
#include "appointmentwindow.h"


namespace Ui {
class DoctorWindow;
}

class DoctorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorWindow(QWidget *parent = 0);
    ~DoctorWindow();
    void initDoctorTableWidget();
    void getDoctorInformation(const QString &id);

private slots:
    void on_GetDoctorPushButton_clicked();
    void addDoctorInformation(const doctor &thedoctor);
    void displayDoctor(void);
private:
    Ui::DoctorWindow *ui;
    DoctorInformationget doctorget;
    AppointmentWindow appointwindow;
};

#endif // DOCTORWINDOW_H
