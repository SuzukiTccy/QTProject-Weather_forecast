#ifndef CURVELB_H
#define CURVELB_H


#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QList>


#include "weatherdata.h"

#define TEMPERATURE_STARTING_COORDINATE 55 // 温度曲线起始坐标
#define SPAN_INDEX  5 // 每度温度对应的像素数，图标区域高度 / 温度显示范围
#define ORIGIN_SIZE 3 // 温度曲线原点大小

class CurveLb : public QLabel{
    /* 绘制温度曲线 */
private:
    QList<Forecast> forcast; // 预测数据

    static const int pointX[6]; // X轴坐标
public:
    explicit CurveLb(QWidget *parent = nullptr);
    ~CurveLb();
    void paintEvent(QPaintEvent *event) override;
    void setForecast(QList<Forecast> forcast);
};

#endif // CURVELB_H
