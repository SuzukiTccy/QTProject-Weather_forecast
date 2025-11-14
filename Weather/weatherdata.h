#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QWidget>


// 当日天气预报的数据
class Today{
public:
    Today();
    Today& operator=(const QJsonObject &jsonObj);
    QString city; // 城市
    QString date; // 日期
    QString temperature; // 温度
    QString shidu; // 湿度
    QString pm25; // PM2.5
    QString quality; // 空气质量
    QString ganmao; // 感冒指数
    QString fx; // 风向
    QString fl; // 风力
    QString type; // 天气类型
    QString sunrise; // 日出时间
    QString sunset; // 日落时间
    QString notice; // 提示
};


// 预报数据
class Forecast{
public:
    Forecast();
    Forecast& operator=(const QJsonObject &jsonObj);
    QString date; // 日期
    QString week; // 星期
    QString high; // 最高温度
    QString low; // 最低温度
    QString quality; // 质量
    QString type; // 天气类型
};

#endif // WEATHERDATA_H