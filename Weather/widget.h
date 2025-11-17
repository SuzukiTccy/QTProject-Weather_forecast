#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QFile>
#include <QPoint>
#include <QLabel>
#include <QList>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QRect>
#include <QDateTime>
#include <QTime>

#include "WeatherTool.h"
#include "weatherdata.h"
#include "qsunriseset.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    /* 右键菜单退出程序 */
    QMenu *m_pMenu;         // 添加一个QMenu指针，右键弹出菜单
    QAction *m_pExitAct;    // 添加一个QAction，退出操作
    QPoint mPos;           // 鼠标位置

    // 预报窗口数据
    QList<QLabel*> forecast_week_list; // 星期
    QList<QLabel*> forecast_date_list; // 日期
    QList<QLabel*> forecast_aqi_list; // 空气质量
    QList<QLabel*> forecast_type_list; // 天气类型
    QList<QLabel*> forecast_typeIco_list; // 天气类型图标
    QList<QLabel*> forecast_high_list; // 最高温度
    QList<QLabel*> forecast_low_list; // 最低温度

    // 网络请求
    QString url; // 网络请求地址
    QString city; // 访问的城市
    QString cityTmp; // 临时存放城市变量，防止输入错误城市的时候，原来的城市名称还在
    WeatherTool tool; // 天气工具对象
    QNetworkAccessManager *manager; // 网络请求对象

    // 天气数据
    Today today; // 今日天气
    QList<Forecast> forecast; // 预报天气

 
protected:
    void contextMenuEvent(QContextMenuEvent *menuEvent); // 重写右键菜单事件
    void slot_exitApp(); // 退出程序槽函数
    void mouseMoveEvent(QMouseEvent *event); // 重写鼠标移动事件
    void mousePressEvent(QMouseEvent *event); // 重写鼠标点击事件

    void getWeatherInfo(QNetworkAccessManager *manager); // 获取天气信息
    void replyFinished(QNetworkReply *reply); // 网络请求完成槽函数
    void parseJson(QByteArray bytes); // 解析json数据
    void initForecastList(); // 初始化天气预报窗口
    void setLabelContent(); // 设置天气数据
}; 

#endif // WIDGET_H
