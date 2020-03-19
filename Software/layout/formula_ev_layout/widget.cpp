#include "widget.h"
#include "ui_widget.h"
#include"QLabel"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    view2 = new QQuickWidget;
    view2->setSource(QUrl::fromLocalFile(":/steering.qml"));
    view2->setFixedSize(310,300);
    view2->updateGeometry();
    //view2->setGeometry(1040,370, view2->width(), view2->height());


    steeringval = 0;

    steering = view2->rootObject();
    steering->setProperty("steering_angle",steeringval);

    speedPlot = new SpeedPlot;
    wheelPlot = new WheelPlot;

    vbar = new VCbar(this);
    //vbar->set_position(420,370);
    c = new current(this);
    vbar->setMax_voltage(200);
    pressure = new Pressure;
    temperature = new Temperature;

    m = new Meter;
   // m->setPostion(420,60);
    m->setType("Speed");


    title = new QLabel("Formula 2020 EV Car");
    QFont font = title->font();
    font.setPixelSize(30);
    title->setFont(font);
    title->setStyleSheet("QLabel { background-color : #252424; color : white;  }");
    //title.setGeometry(0,5,1400,50);
    title->setAlignment(Qt::AlignCenter);

    layoutTitle = new QHBoxLayout;
    layoutTitle->addWidget(title);

    layoutTop = new QHBoxLayout;
    layoutTop->addWidget(wheelPlot);
    layoutTop->addWidget(m);
    layoutTop->addWidget(pressure);
    layoutTop->addWidget(temperature);

    layoutBottom= new QHBoxLayout;
    layoutBottom->addWidget(speedPlot);
    layoutBottom->addWidget(vbar);
    layoutBottom->addWidget(c);
    layoutBottom->addWidget(view2);

    vlayout = new QVBoxLayout;
    vlayout->addLayout(layoutTitle);
    vlayout->addLayout(layoutTop);
    vlayout->addLayout(layoutBottom);

    this->setLayout(vlayout);

    serial = new QSerialPort(this);
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    serial->write("ok");
    connect(serial,SIGNAL(readyRead()),this,SLOT(serial_receive()));



}

Widget::~Widget()
{
    delete ui;
    serial->close();
}

void Widget::serial_receive()
{    bool ok;
     ba = serial->readAll();
     buffer = QString::fromStdString(ba.toHex(' ').toStdString());
     QStringList list = buffer.split(' ');
     if(list.length()== 7)
     {
         pressure->updateValue(list[0].toInt(&ok,16));
         temperature->updateTemperature(list[1].toInt(&ok,16));
         m->update_values(list[2].toInt(&ok,16));
         speedPlot->updateValue(list[3].toInt(&ok,16));
         vbar->update_voltage(list[4].toInt(&ok,16));
         steering->setProperty("steering_angle",list[5].toInt(&ok,16));
         c->updateCurrent(list[6].toInt(&ok,16));

         qDebug()<<(list[0].toInt(&ok,16));
         qDebug()<<(list[1].toInt(&ok,16));
         qDebug()<<(list[2].toInt(&ok,16));
         qDebug()<<(list[3].toInt(&ok,16));
         qDebug()<<(list[4].toInt(&ok,16));
         qDebug()<<(list[5].toInt(&ok,16));
         qDebug()<<(list[6].toInt(&ok,16));
     }
     else{
         qDebug()<<"no";
     }
}

