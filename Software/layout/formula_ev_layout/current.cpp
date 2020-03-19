#include "current.h"

current::current(QWidget *parent) : QWidget(parent)
{
    title  = new QLabel(this);
    symbol = new QLabel(this);
    reading = new QLabel(this);
    current_value = 0;


    title->setText("Motor Current");
    title->setGeometry(30, 10, 200, 100);
    title->setStyleSheet("QLabel { color : white; }");

    QFont font = title->font();
    font.setPixelSize(20);
    title->setFont(font);

    reading->setText(QString::number(current_value)+" "+"A");
    reading->setGeometry(30, 150, 100, 30);
    reading->setStyleSheet("QLabel { color : white; }");

    font = reading->font();
    font.setPixelSize(30);
    reading->setFont(font);

    setFixedSize(300,300);
    updateGeometry();
}

void current::setPostion(qreal x, qreal y)
{
    setGeometry(x,y,300,300);
}

void current::updateCurrent(int value)
{
    if(value>200)
    {
        value=0;
    }
    current_value = value;
    reading->setText(QString::number(current_value)+" "+"A");
}


void current::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QBrush brush (QColor(QString("#252424")),Qt::SolidPattern);
    QRect rect (0,0,500,300);
    painter.drawRect(rect);
    painter.fillRect(rect,brush);

   // QPixmap flash ("D:/ASURT/Qt/formula_ev/logo.png");
    QPixmap flash (":/images/images/logo.png");
    symbol->setPixmap(flash);
    QSize s = flash.size();
    symbol->setGeometry(150,100, s.width()/5, s.height()/5);
    symbol->setScaledContents(true);
}
