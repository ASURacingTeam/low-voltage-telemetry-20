#ifndef METER_H
#define METER_H

#include <QObject>
#include<QPainter>
#include<QBrush>
#include<QPropertyAnimation>
#include<QPen>
#include<QTimerEvent>
#include<QVector>
#include<QDebug>
#include<QPaintEvent>
#include<QWidget>
class Meter : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)
public:
    explicit Meter(QWidget *parent = nullptr);
    qreal value() const;
    void setValue(qreal value);

    QColor getColor() const ;
    void setColor(QColor color);


    void setType(QString type);
    void setPostion(qreal x,qreal y);

    void update_values(uint8_t value);


signals:
    void valueChanged();
    void colorChanged();

protected:

    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:

    qreal m_value;
    qreal newValue;
    QPropertyAnimation m_animation;

    QColor arcColor;
    QPropertyAnimation c_animation;

    QString meterUnit;
    QString meterTitle;
    qreal spanfactor;
    qreal maxValue;
    QString meter_type;


};

#endif // METER_H
