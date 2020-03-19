#ifndef CURRENT_H
#define CURRENT_H

#include <QWidget>
#include<QLabel>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QTimerEvent>
#include <QDebug>
class current : public QWidget
{
    Q_OBJECT
public:
    explicit current(QWidget *parent = nullptr);
    void setPostion(qreal x,qreal y);
    void updateCurrent(int value);

signals:

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;


private:
    QLabel* title ;
    QLabel* symbol;
    qreal current_value;
    QLabel* reading;
};

#endif // CURRENT_H
