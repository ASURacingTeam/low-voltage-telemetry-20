#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include <QtQuickWidgets>
#include <meter.h>
#include <pressure.h>
#include <speedplot.h>
#include <temperature.h>
#include <VCbar.h>
#include <wheelplot.h>
#include <QSerialPort>
#include<QHBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void serial_receive();

private:
    Ui::Widget *ui;
    QQuickWidget *view ;
    QQuickWidget *view2 ;
    QObject *gear ;
    QObject *steering ;
    WheelPlot *wheelPlot;
    SpeedPlot *speedPlot;
    VCbar *vbar;
    Pressure *pressure;
    Temperature *temperature;
    Meter *m;
    Meter *m2;
    QSerialPort *serial;
    QByteArray ba;
    QString buffer;
    int timer_id;
    int gearval;
    int steeringval;
    QLabel *title;
    QHBoxLayout *layoutTop;
    QHBoxLayout *layoutBottom;
    QHBoxLayout *layoutTitle;
    QVBoxLayout *vlayout;
};
#endif // WIDGET_H
