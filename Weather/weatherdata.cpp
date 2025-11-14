#include "weatherdata.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDateTime>


Today::Today(){
    this->data = "0000-00-00";
    this->city = "null";
    this->fl = u8"无数据";
    this->fx = u8"无数据";
    this->ganmao = u8"无数据";
    this->notice = u8"无数据";
    this->pm25 = u8"无数据";
    this->quality = u8"无数据";
    this->shidu = u8"无数据";
    this->sunrise = "00:00";
    this->sunset = "00:00";
    this->temperature = "null";
    this->type = u8"无数据";
}

Today& Today::operator=(const QJsonObject &jsonObj){
    QString dataStr = jsonObj.value("date").toString();
    this->data = QDate::fromString(dataStr, "yyyyMMdd").toString("yyyy-MM-dd");
    this->city = jsonObj.value("cityInfo").toObject().value("city").toString();

    // 解析data
    QJsonObject dataObj = jsonObj.value("data").toObject();
    this->shidu = dataObj.value("shidu").toString();
    this->pm25 = dataObj.value("pm25").toString();
    this->quality = dataObj.value("quality").toString();
    this->temperature = dataObj.value("wendu").toString() + u8"℃";
    this->ganmao = dataObj.value("ganmao").toString();
    QJsonArray forecastArr = dataObj.value("forecast").toArray();
    QJsonObject todayObj = forecastArr.at(0).toObject();
    this->fx = todayObj.value("fx").toString();
    this->fl = todayObj.value("fl").toString();
    this->type = todayObj.value("type").toString();
    this->sunrise = todayObj.value("sunrise").toString();
    this->sunset = todayObj.value("sunset").toString();
    this->notice = todayObj.value("notice").toString();
    return *this;
}

Forecast::Forecast(){
    this->date = u8"00 日星期 0";
    this->quality = "0";
    this->week = u8"星期 0";
    this->high = u8"最高温度 0.0℃";
    this->low = u8"最低温度 0.0℃";
    this->type = "undefined";
}


Forecast& Forecast::operator=(const QJsonObject &jsonObj){
    this->date = jsonObj.value("date").toString();
    this->week = jsonObj.value("week").toString();
    this->high = jsonObj.value("high").toString();
    this->low = jsonObj.value("low").toString();
    this->quality = QString::number(jsonObj.value("api").toDouble());
    this->type = jsonObj.value("type").toString();
    return *this;
}