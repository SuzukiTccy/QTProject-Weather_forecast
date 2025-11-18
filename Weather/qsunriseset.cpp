#include "qsunriseset.h"


QSunRiseSet::QSunRiseSet(QWidget *parent) : QLabel(parent){
    this->today = Today();
}

QSunRiseSet::~QSunRiseSet(){}

void QSunRiseSet::setToday(const Today &today){
    this->today = today;
}

// 绘制日落日出图的水平线的相对坐标
const QPoint QSunRiseSet::sun[2] = {
    QPoint(10, 76),
    QPoint(140, 76)
};

// 绘制出日落日出时间的相对坐标
const QRect QSunRiseSet::sunRiseSetRect[2] = {
    QRect(-10, 77, 50, 20),
    QRect(110, 77, 50, 20)
};

// 绘制日落日出圆弧
const QRect QSunRiseSet::rect[2] = {
    QRect(15, 15, 120, 120), // 虚线圆弧
    QRect(50, 77, 50, 20) // "日落日出"文本
};


void QSunRiseSet::paintEvent(QPaintEvent *event){

    // 先调用父类的绘制，确保QLabel的基本功能（如文字显示）正常
    QLabel::paintEvent(event); 

    QPainter painter(this); // 在sunRiseSetLb上绘制
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
    painter.save(); // 保存当前绘制器状态（将状态推送到堆栈上）
    QPen pen = painter.pen();
    pen.setWidthF(0.5); // 设置画笔宽度, 单位为浮点值像素
    pen.setColor(Qt::yellow); // 设置画笔颜色
    painter.setPen(pen); // 设置画笔
    painter.drawLine(this->sun[0], this->sun[1]); // 绘制日出日落水平线
    painter.restore(); // 恢复之前保存的绘制器状态（从堆栈上弹出并恢复状态）
    
    painter.save();
    painter.setFont(QFont("Arial", 10, QFont::Normal)); // 设置字体
    painter.setPen(Qt::white); // 设置画笔颜色
    if(this->today.sunrise != "" && this->today.sunset != ""){
        // 在制定区域内绘制文字
        painter.drawText(this->sunRiseSetRect[0], Qt::AlignCenter, this->today.sunrise);
        painter.drawText(this->sunRiseSetRect[1], Qt::AlignCenter, this->today.sunset);
    }
    painter.drawText(this->rect[1], Qt::AlignCenter, u8"日落日出"); // 在制定区域内绘制文字
    painter.restore();

    // 绘制圆弧
    painter.save();
    pen.setWidthF(0.5); // 设置画笔宽度, 单位为浮点值像素
    pen.setStyle(Qt::DotLine); // 虚线
    pen.setColor(Qt::green); // 设置画笔颜色
    painter.setPen(pen); // 设置画笔
    painter.drawArc(this->rect[0], 0 * 16, 180 * 16); // 绘制圆弧
    painter.restore();

    // 绘制日出日落占比
    painter.save();
    if(this->today.sunrise != "" && this->today.sunset != ""){
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(255,85,0,100)); // 设置填充颜色

        int startAngle = 0, spanAngle = 0;
        QString sunsetTime = this->today.date + " " + this->today.sunset;
        if(QDateTime::currentDateTime() > QDateTime::fromString(sunsetTime, "yyyy-MM-dd HH:mm")){
            // 当前时间已经日落
            startAngle = 0 * 16;
            spanAngle = 180 * 16;
        }
        else{
            // 计算起始角度和跨越角度
            static QStringList sunRiseTime = this->today.sunrise.split(":");
            static QStringList sunSetTime = this->today.sunset.split(":");

            static QString sunriseHour = sunRiseTime.at(0);
            static QString sunriseMint = sunRiseTime.at(1);
            static QString sunsetHour = sunSetTime.at(0);
            static QString sunsetMint = sunSetTime.at(1);

            static int sunrise = sunriseHour.toInt() * 60 + sunriseMint.toInt();
            static int sunset = sunsetHour.toInt() * 60 + sunsetMint.toInt();
            int now = QTime::currentTime().hour() * 60 + QTime::currentTime().minute();

            // 180度是半圆的弧度，drawArc函数使用的角度单位是1/16度，所以我们需要将角度乘以16
            startAngle = ((double)(sunset - now) / (sunset - sunrise)) * 180 * 16;
            spanAngle = ((double)(now - sunrise) / (sunset - sunrise)) * 180 * 16;
        }
        if(startAngle >= 0 && spanAngle >= 0){
            painter.drawPie(this->rect[0], startAngle, spanAngle); // 绘制扇形
        }
    }
    painter.restore();
}


