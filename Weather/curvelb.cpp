#include "curvelb.h"


CurveLb::CurveLb(QWidget *parent) : QLabel(parent){
    // 初始化forecast
    for(int i = 0; i < 6; ++i){
        this->forecast.append(Forecast());
    }
}

CurveLb::~CurveLb(){}

void CurveLb::setForecast(QList<Forecast> forecast){
    this->forecast.clear();
    for(int i = 0; i < forecast.size(); ++i){
        this->forecast.append(forecast[i]);
    }
}

const int CurveLb::pointX[6] = {35, 108, 183, 258, 332, 408};

void CurveLb::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true); // 设置抗锯齿

    // 温度数据
    int tempTotal = 0;
    int high[6] = {0, 0, 0, 0, 0, 0};
    int low[6] = {0, 0, 0, 0, 0, 0};

    QString h, l;
    for(int i = 0; i < 6; ++i){
        h = this->forecast[i].high.split(" ").at(1); // forcast[i].high = "高温 20℃"
        h = h.left(h.length() - 1); // h = "20℃" -> "20"
        high[i] = (int)(h.toDouble());
        tempTotal += high[i];

        l = this->forecast[i].low.split(" ").at(1);
        l = l.left(l.length() - 1);
        low[i] = (int)(l.toDouble());
    }
    int highestTempAverage = (int)(tempTotal / 6); // 最高温度平均值

    // 温度曲线坐标
    int pointHY[6] = {0, 0, 0, 0, 0, 0}; // 最高温度曲线点Y坐标
    int pointLY[6] = {0, 0, 0, 0, 0, 0}; // 最低温度曲线点Y坐标
    for(int i = 0; i < 6; ++i){
        pointHY[i] = TEMPERATURE_STARTING_COORDINATE + (high[i] - highestTempAverage) * SPAN_INDEX;
        pointLY[i] = TEMPERATURE_STARTING_COORDINATE - (highestTempAverage - low[i]) * SPAN_INDEX;
    }

    QPen pen = painter.pen();

    // 高温曲线绘制
    painter.save();
    pen.setWidth(1); // 设置画笔宽度为1
    pen.setColor(QColor(255, 170, 0)); // 设置画笔颜色
    pen.setStyle(Qt::DotLine); // 设置画笔样式
    painter.setPen(pen);
    painter.setBrush(QColor(255, 170, 0)); // 设置画刷颜色

    // 画原点
    painter.drawEllipse(QPoint(this->pointX[0], pointHY[0]), ORIGIN_SIZE, ORIGIN_SIZE);
    painter.drawEllipse(QPoint(this->pointX[1], pointHY[1]), ORIGIN_SIZE, ORIGIN_SIZE);

    // 画虚线
    painter.drawLine(this->pointX[0], pointHY[0], this->pointX[1], pointHY[1]);

    // 画实线
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    painter.setPen(pen);

    for(int i = 1; i < 5; ++i){
        painter.drawEllipse(QPoint(this->pointX[i+1], pointHY[i+1]), ORIGIN_SIZE, ORIGIN_SIZE);
        painter.drawLine(this->pointX[i], pointHY[i], this->pointX[i+1], pointHY[i+1]);
    }

    painter.restore();

    // 最低温度曲线绘制
    painter.save();
    pen.setColor(QColor(0, 255, 255)); // 设置画笔颜色
    pen.setStyle(Qt::DotLine); // 设置画笔样式
    painter.setPen(pen);
    painter.setBrush(QColor(0, 255, 255)); // 设置画刷颜色
    
    // 画原点
    painter.drawEllipse(QPoint(this->pointX[0], pointLY[0]), ORIGIN_SIZE, ORIGIN_SIZE);
    painter.drawEllipse(QPoint(this->pointX[1], pointLY[1]), ORIGIN_SIZE, ORIGIN_SIZE);

    // 画虚线
    painter.drawLine(this->pointX[0], pointLY[0], this->pointX[1], pointLY[1]);

    // 画实线
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    painter.setPen(pen);
    for(int i = 1; i < 5; ++i){
        painter.drawEllipse(QPoint(this->pointX[i+1], pointLY[i+1]), ORIGIN_SIZE, ORIGIN_SIZE);
        painter.drawLine(this->pointX[i], pointLY[i], this->pointX[i+1], pointLY[i+1]);
    }
    painter.restore();

}
