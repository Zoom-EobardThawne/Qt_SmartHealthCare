#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class DataWindow;
}

class DataWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataWindow(QWidget *parent = 0);
    ~DataWindow();
    void cleanWindow();

    QString getUsername() const;
    void setUsername(const QString &value);

private slots:
    void on_commitPushButton_clicked();
    void handleReplyData();

private:
    Ui::DataWindow *ui;
    QTcpSocket tcpSocket;
    QString username;
};

#endif // DATAWINDOW_H
