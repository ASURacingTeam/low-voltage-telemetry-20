#include "VCbar.h"

VCbar::VCbar(QWidget *parent) : QWidget(parent)
{
    volt = 0;
    setFixedSize(300,300);
    updateGeometry();
    v_bar = new QProgressBar(this);
    v_label = new QLabel(this);
    v_title = new QLabel(this);
    v_value = new QLabel(this);
    v_capcity = new QLabel(this);

    font = new QFont();
    font = &(v_label->font());
    (( QFont*)font)->setPixelSize(15);
    font = &(v_title->font());
    ((QFont*)font)->setPixelSize(20);

    font = &(v_capcity->font());
    ((QFont*)font)->setPixelSize(20);

    font = &(v_value->font());
    ((QFont*)font)->setPixelSize(50);
    v_value->setStyleSheet("QLabel { background-color : #252424; color : #F82019;}");

    v_title->setStyleSheet("QLabel { background-color : #252424; color : white;}");
    v_title->setText("Battery Voltage");
    v_title->setGeometry(50,30,200,40);

    v_capcity->setStyleSheet("QLabel { background-color : #252424; color : white;}");
    v_capcity->setText("Battery Capcitance");
    v_capcity->setGeometry(50,180,200,40);


    v_bar->setRange(0,100);
    v_bar->setTextVisible(false);
    v_bar->setStyleSheet(QString("QProgressBar:horizontal {\
                                border: 1px solid white;\
                                border-radius: 5px;\
                                background: #2C2B2B;\
                                padding: 1px;\
                                }\
                                QProgressBar::chunk:horizontal {\
                                background: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0 #F82019, stop: 1 darkred);\
                                }"));

     v_label->setStyleSheet("QLabel { background-color : #252424; color : white;  }");
     v_value->setGeometry(80,80,200,100);


     layout =new QHBoxLayout (this);
     layout->addWidget(v_bar);
     layout->addWidget(v_label);
     layout->setAlignment(Qt::AlignBottom);
     layout->setMargin(35);
     setLayout(layout);

     v_bar->setValue(0);
     v_label->setText(QString::number(0)+" "+QString("%"));
     v_value->setText(QString::number(volt)+" "+QString("Volt"));

}

void VCbar::set_position(qreal x, qreal y)
{
    this->setGeometry(x,y,300,300);
}



void VCbar::setMax_voltage(qreal volt)
{
    max_voltage = volt;
}

void VCbar::update_voltage(uint8_t voltage)
{
    if (voltage > max_voltage) voltage = 12;
    volt =voltage;
    if(volt>(2*max_voltage/3) && volt<=max_voltage)
    {
        v_value->setStyleSheet("QLabel { background-color : #252424; color : #008710;}");
        //font become small again without this line
        ((QFont*)font)->setPixelSize(50);
        v_bar->setStyleSheet(QString("QProgressBar:horizontal {\
                                     border: 1px solid white;\
                                     border-radius: 5px;\
                                     background: #2C2B2B;\
                                     padding: 1px;\
                                     }\
                                    QProgressBar::chunk:horizontal {\
                                    background: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0 #008710, stop: 1 darkgreen);\
                                    }"));

    }
    else if(volt >(max_voltage/3) && volt<=(2*max_voltage/3))
    {
        v_value->setStyleSheet("QLabel { background-color : #252424; color : #E27930 ;}");
        ((QFont*)font)->setPixelSize(50);
        v_bar->setStyleSheet(QString("QProgressBar:horizontal {\
                                     border: 1px solid white;\
                                     border-radius: 5px;\
                                     background: #2C2B2B;\
                                     padding: 1px;\
                                     }\
                                    QProgressBar::chunk:horizontal {\
                                    background: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0 #E27930, stop: 1 darkorange);\
                                    }"));
    }

    else if(volt >=0 && volt<=(max_voltage/3))
    {
        v_value->setStyleSheet("QLabel { background-color : #252424; color : #F82019;}");
        ((QFont*)font)->setPixelSize(50);
        v_bar->setStyleSheet(QString("QProgressBar:horizontal {\
                                     border: 1px solid white;\
                                     border-radius: 5px;\
                                     background: #2C2B2B;\
                                     padding: 1px;\
                                     }\
                                    QProgressBar::chunk:horizontal {\
                                    background: qlineargradient(x1: 0, y1: 0.5, x2: 1, y2: 0.5, stop: 0 #F82019, stop: 1 darkred);\
                                    }"));
    }
    v_bar->setValue((volt/max_voltage)*100);
    v_label->setText(QString::number(int((volt/max_voltage)*100))+" "+QString("%"));
    v_value->setText(QString::number(volt)+" "+QString("Volt"));

}

void VCbar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    QBrush brush (QColor(QString("#252424")),Qt::SolidPattern);
    QRect rect (0,0,400,300);
    painter.drawRect(rect);
    painter.fillRect(rect,brush);
}

