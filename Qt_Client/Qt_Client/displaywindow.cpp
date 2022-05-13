#include "displaywindow.h"
#include <QPainter>

DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{

}

void DisplayWindow::paintEvent(QPaintEvent *event)
{
    if(!image.isNull()){
        QPainter painter(this);
        painter.drawImage(this->rect(),image);

    }
}

void DisplayWindow::updatePicture(const QByteArray &data)
{
    image=QImage::fromData(data);
    update();
}

void DisplayWindow::displayPicture(const QString &filename)
{
    image.load(filename);
    update();//触发painEvent函数执行
}
