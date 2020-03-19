#ifndef VCBAR_H
#define VCBAR_H

#include <QWidget>
#include<QtGui>
#include<QProgressBar>
#include<QPainter>
#include<QPaintEvent>
#include<QLayout>
#include<QLabel>
#include<QPropertyAnimation>
#include<QDebug>
class VCbar : public QWidget
{
    Q_OBJECT

public:
    explicit VCbar(QWidget *parent = nullptr);
    void set_position(qreal x,qreal y);
    void setMax_voltage(qreal volt);
    void update_voltage(uint8_t voltage);


protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;


private:
QProgressBar* v_bar;
QLabel* v_label;
QLabel* v_title;
QLabel* v_capcity;
QHBoxLayout* layout ;
QLabel* v_value;
const QFont* font;
qreal volt;
qreal max_voltage;
};

#endif //VCBAR_H
