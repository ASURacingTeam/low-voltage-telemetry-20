#ifndef SPEEDPLOT_H
#define SPEEDPLOT_H

#include <QObject>
#include <QWidget>
#include <qcustomplot.h>
#include <QTimer>

class SpeedPlot : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedPlot(QWidget *parent = nullptr);

    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    void customizePlot(QCustomPlot *customPlot);
    void updateValue(uint8_t value);

private slots:
    void realtimeDataSlot();

private:
    QCustomPlot *customPlot;
    QString demoName;
    QTimer dataTimer;
    uint8_t speed_value = 50;
    uint8_t acceleration_value = 30;
};

#endif // SPEEDPLOT_H
