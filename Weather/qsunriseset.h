#ifndef SUNSRISESET_H
#define SUNSRISESET_H

#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QRect>
#include <QDateTime>
#include <QTime>


#include "weatherdata.h"



class QSunRiseSet : public QLabel{
    Q_OBJECT
private:
    // 绘制日落日出时间
    static const QPoint sun[2]; // 绘制日落日出图的水平线的相对坐标
    static const QRect sunRiseSetRect[2]; // 绘制出日落日出时间的相对坐标
    static const QRect rect[2]; // 绘制日落日出圆弧

    // 今日天气
    Today today; // 天气数据

public:
    explicit QSunRiseSet(QWidget *parent = nullptr);
    ~QSunRiseSet();

    void paintEvent(QPaintEvent *event) override;
    void setToday(const Today& today);
};

#endif
