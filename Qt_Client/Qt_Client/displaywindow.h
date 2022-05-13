#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>

class DisplayWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void updatePicture(const QByteArray &data);
signals:

public slots:
    void displayPicture(const QString &filename);

private:
    QImage image;
};

#endif // DISPLAYWINDOW_H
