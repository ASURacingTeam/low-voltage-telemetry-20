#include "temperature.h"

Temperature::Temperature(QWidget *parent) : QWidget(parent)
{
    //setGeometry(1040,60,200,300);
    setFixedSize(50,300);
    updateGeometry();
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, QColor(QString("#252424")));
    this->setPalette(pal);
    temp = new QLabel(this);
    lblTemp = new QLabel(this);
    lblTemp->setText("100 C");
    lblTemp->setGeometry(0, 10, 60, 30);
    lblTemp->setStyleSheet("QLabel { color : red; }");
    QFont font = lblTemp->font();
    font.setPointSize(10);
    font.setBold(true);
    lblTemp->setFont(font);
    temp_animation.setTargetObject(this);
    temp_animation.setPropertyName("temperature");
    height_animation.setTargetObject(this);
    height_animation.setPropertyName("height");
    timer_id = startTimer(1000);
}

qreal Temperature::temperature() const
{
     return t_temp;
}

void Temperature::setTemperature(qreal temperature)
{
    if (qFuzzyCompare(t_temp, temperature))
        return;

    t_temp = temperature;
    update();
    emit temperatureChanged();

}

qreal Temperature::height() const
{
    return h_height;
}

void Temperature::setHeight(qreal height)
{
    if (qFuzzyCompare(h_height, height))
        return;

    h_height = height;
    update();
    emit heightChanged();

}

void Temperature::paintEvent(QPaintEvent *)
{
    QPainter painter2(this);
    painter2.setRenderHint(QPainter::Antialiasing);
    QBrush brush (QColor(QString("#252424")),Qt::SolidPattern);
    QRect rect (0,0,60,300);
    painter2.drawRect(rect);
    painter2.fillRect(rect,brush);

   // QPixmap pm("D:/ASURT/Qt/Formula2020/thermo.png");
    QPixmap pm(":/images/images/thermo.png");
    QPainter p(&pm);
    p.setPen(Qt::red);
    p.setBrush(Qt::red);
    p.drawRect(72, t_temp, 79, h_height);
    temp->setPixmap(pm);
    QSize s = pm.size();
    temp->setGeometry(0, 45, s.width()/5, s.height()/5);
    temp->setScaledContents(true);
    update();
}

void Temperature::timerEvent(QTimerEvent *event)
{
        if (event->timerId() == timer_id) {

            qreal newValue = 0;
            qreal newHeight = 0;
            newValue = 980 - ((newTemp-20) * 10.2);
            newHeight = 10.2 * (newTemp - 20);
            if (newTemp > maxTemp)
            {
                t_temp = maxValue;
                h_height = maxHeight;
            }

            if (temp_animation.state() == QPropertyAnimation::Running)
                temp_animation.stop();
            if (height_animation.state() == QPropertyAnimation::Running)
                height_animation.stop();
            temp_animation.setStartValue(t_temp);
            temp_animation.setEndValue(newValue);
            height_animation.setStartValue(h_height);
            height_animation.setEndValue(newHeight);
            temp_animation.start();
            height_animation.start();
            lblTemp->setText(QString::number(newTemp) + " C");
        }
}

void Temperature::updateTemperature(uint8_t value)
{
    newTemp = value;
}
