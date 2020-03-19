#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QtQuickWidgets>
#include <current.h>
#include <meter.h>
#include <pressure.h>
#include <speedplot.h>
#include <temperature.h>
#include <VCbar.h>
#include <wheelplot.h>
#include <QSerialPort>
#include<QLabel>
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
    QQuickWidget *view2 ;
    QObject *steering ;
    WheelPlot *wheelPlot;
    SpeedPlot *speedPlot;
    VCbar *vbar;
    Pressure *pressure;
    Temperature *temperature;
    Meter *m;
    QSerialPort *serial;
    QByteArray ba;
    QString buffer;
    int timer_id;
    int steeringval;
    QLabel *title;
    QHBoxLayout *layoutTop;
    QHBoxLayout *layoutBottom;
    QHBoxLayout *layoutTitle;
    QVBoxLayout *vlayout;
    current *c;
};
#endif // WIDGET_H
