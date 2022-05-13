#ifndef DIAGNOSEWINDOW_H
#define DIAGNOSEWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class diagnoseWindow;
}

class diagnoseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit diagnoseWindow(QWidget *parent = 0);
    ~diagnoseWindow();
public slots:
    void displayWindow();
    void doctorOpinion(const QByteArray &data);

private slots:
    void on_pushButton_clicked();
    void handleReplyData();

private:
    Ui::diagnoseWindow *ui;
    QTcpSocket tcpSocket;
};

#endif // DIAGNOSEWINDOW_H
