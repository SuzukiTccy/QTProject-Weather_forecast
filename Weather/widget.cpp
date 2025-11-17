#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置窗口属性，设置成无边框
    this->setWindowFlag(Qt::FramelessWindowHint);

    //右键菜单
    this->m_pMenu = new QMenu(this);
    this->m_pExitAct = new QAction(this);
    this->m_pExitAct->setIconVisibleInMenu(true); //设置图标在菜单中可见，在macos上，默认不可见，所以这里强制打开
    this->m_pExitAct->setText(u8"退出");
    this->m_pExitAct->setIcon(QIcon(":/weatherIco/close.ico"));
    this->m_pMenu->addAction(this->m_pExitAct);

    //连接信号和槽
    // connect(this->m_pExitAct, SIGNAL(triggered(bool)), this, SLOT(this->slot_exitApp())); // 旧语法
    connect(this->m_pExitAct, &QAction::triggered, this, &Widget::slot_exitApp); // 新语法


    // 预报窗口数据
    // 等价于多次调用append()
    this->forecast_week_list << ui->week0Lb << ui->week1Lb << ui->week2Lb << ui->week3Lb << ui->week4Lb << ui->week5Lb;
    this->forecast_date_list << ui->date0Lb << ui->date1Lb << ui->date2Lb << ui->date3Lb << ui->date4Lb << ui->date5Lb;
    this->forecast_aqi_list << ui->quality0Lb << ui->quality1Lb << ui->quality2Lb << ui->quality3Lb << ui->quality4Lb << ui->quality5Lb;
    this->forecast_type_list << ui->type0Lb << ui->type1Lb << ui->type2Lb << ui->type3Lb << ui->type4Lb << ui->type5Lb;
    this->forecast_typeIco_list << ui->typeIco0Lb << ui->typeIco1Lb << ui->typeIco2Lb << ui->typeIco3Lb << ui->typeIco4Lb << ui->typeIco5Lb;
    this->forecast_high_list << ui->high0Lb << ui->high1Lb << ui->high2Lb << ui->high3Lb << ui->high4Lb << ui->high5Lb;
    this->forecast_low_list << ui->low0Lb << ui->low1Lb << ui->low2Lb << ui->low3Lb << ui->low4Lb << ui->low5Lb;

    // dateLb和WeekLb样式表
    for(int i = 0; i < this->forecast_date_list.size(); i++)
    {
        this->forecast_date_list[i]->setStyleSheet("background-color: rgba(0, 255, 255, 100);");
        this->forecast_week_list[i]->setStyleSheet("background-color: rgba(0, 255, 255, 100);");
    }

    // 搜索框样式表
    ui->cityLineEdit->setStyleSheet("QLineEdit{ \
    border: 1px solid gray; \
    border-radius: 4px; \
    background:rgba(47,47,47,130); \
    color: rgb(255,255,255);} \
    QLineEdit:hover{border-color: rgb(101, 255, 106);}");

    // 请求天气API信息
    this->url = "http://t.weather.itboy.net/api/weather/city/";
    this->city = u8"深圳";
    this->cityTmp = this->city;
    this->manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Widget::replyFinished);
    this->getWeatherInfo(this->manager);

    // 初始化Forecast列表
    this->initForecastList();

    // 更新数据
    this->setLabelContent();

    // 绘制日落日出图
    ui->sunRiseSetLb->setToday(this->today);
    
}

Widget::~Widget()
{
    delete ui;
}


void Widget::contextMenuEvent(QContextMenuEvent *menuEvent)
{
    this->m_pMenu->exec(QCursor::pos()); //在鼠标位置显示右键菜单
    menuEvent->accept(); //接受事件
}

void Widget::slot_exitApp()
{
    qApp->exit(0); //退出程序
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    // 鼠标相对于窗口的位置
    // globalPos() 获取的是鼠标相对于屏幕的位置(全局坐标)
    // pos() 获取应用窗口左上角相对于屏幕左上角的位置
    this->mPos = event->globalPosition().toPoint() - this->pos(); // mPos相当于鼠标在窗口中的位置
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{   
    // 更改窗口位置
    // this->pos() = event->globalPos() - this->mPos;
    this->move(event->globalPosition().toPoint() - this->mPos);
}

void Widget::getWeatherInfo(QNetworkAccessManager *manager){
    QString citycode = this->tool[this->city];
    if(citycode == "000000000"){
        QMessageBox::warning(this, u8"错误", u8"指定城市不存在！", QMessageBox::Ok);
        return;
    }
    QUrl jsonUrl(this->url + citycode);
    manager->get(QNetworkRequest(jsonUrl));
}

void Widget::replyFinished(QNetworkReply *reply){
    /* 获取响应的信息，状态码为200表示正常 */
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    QString error_reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    /*
    除了状态码，我们还要检查reply->error()。因为有些错误可能发生在网络层（如连接超时、主机不可达等），
    此时状态码可能无效，而reply->error()会返回非NoError的值。
    */
    if(reply->error() != QNetworkReply::NoError){
        // 网络层错误（连接失败, 超时等）
        QMessageBox::warning(this, u8"错误", u8"网络错误！" + reply->errorString(), QMessageBox::Ok);
    }else if(status_code != 200){
        // HTTP协议层错误
        QMessageBox::warning(this, u8"错误", u8"服务器返回错误: " + status_code.toString() + \
        "\n" + error_reason, QMessageBox::Ok);
    }
    QByteArray bytes = reply->readAll();
    // qDebug() << bytes; // 打印JSON数据
    this->parseJson(bytes); // 解析JSON数据
}

void Widget::parseJson(QByteArray bytes){
    QJsonParseError err;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes, &err);
    if(err.error != QJsonParseError::NoError){
        QMessageBox::warning(this, u8"错误", u8"解析JSON数据失败！", QMessageBox::Ok);
        return;
    }
    QJsonObject jsObj = jsonDoc.object();
    QString message = jsObj.value("message").toString();
    if(message.contains("success") == false){
        QMessageBox::information(this, tr("The information of Json_desc"), u8"天气：城市错误", QMessageBox::Ok);
        this->city = this->cityTmp;
        return;
    }

    this->today = jsObj;
    // 解析data中的yesterday
    QJsonObject dataObj = jsObj.value("data").toObject();
    this->forecast[0] = dataObj.value("yesterday").toObject();
    // 解析data中的forecast
    QJsonArray forecastArr = dataObj.value("forecast").toArray();
    for(int i = 1; i < this->forecast_date_list.size(); i++){
        this->forecast[i] = forecastArr[i-1].toObject();
    }
}

void Widget::initForecastList(){
    // 初始化Forecast列表
    for(int i = 0; i < this->forecast_date_list.size(); i++){
        this->forecast << Forecast();
    }
}

void Widget::setLabelContent(){
    QEventLoop eventloop;
    QTimer::singleShot(1000, &eventloop, &QEventLoop::quit);
    eventloop.exec();
    // 今日数据
    ui->citydateLb->setText(this->today.date);
    ui->cityTemLb->setText(this->today.temperature);
    ui->cityLocLb->setText(this->today.city);
    ui->cityWeaLb->setText(this->today.type);
    ui->noticeLb->setText(this->today.notice);
    ui->shiduLb->setText(this->today.shidu);
    ui->pm25Lb->setText(this->today.pm25);
    ui->fxLb->setText(this->today.fx);
    ui->flLb->setText(this->today.fl);
    ui->ganmaoBrowser->setText(this->today.ganmao);

    // Forecast数据
    for(int i = 0; i < this->forecast_date_list.size(); i++){
        this->forecast_week_list[i]->setText(this->forecast[i].week.right(3));
        this->forecast_date_list[i]->setText(forecast[i].date.left(3));
        this->forecast_type_list[i]->setText(forecast[i].type);
        this->forecast_high_list[i]->setText(forecast[i].high.split(" ").at(1));
        this->forecast_low_list[i]->setText(forecast[i].low.split(" ").at(1));
        this->forecast_typeIco_list[i]->setStyleSheet( tr("image:url(:/day/day/%1.png);").arg(forecast[i].type));

        // 空气质量
        if (this->forecast[i].aqi.toInt() >= 0 && this->forecast[i].aqi.toInt() <= 50){
            this->forecast_aqi_list[i]->setText(u8"优");
            this->forecast_aqi_list[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
        else if(this->forecast[i].aqi.toInt() > 50 && this->forecast[i].aqi.toInt() <= 100){
            this->forecast_aqi_list[i]->setText(u8"良");
            this->forecast_aqi_list[i]->setStyleSheet("color: rgb(255, 255, 0);");
        }
        else if(this->forecast[i].aqi.toInt() > 100 && this->forecast[i].aqi.toInt() <= 150){
            this->forecast_aqi_list[i]->setText(u8"轻度污染");
            this->forecast_aqi_list[i]->setStyleSheet("color: rgb(255, 170, 0);");
        }
        else if(this->forecast[i].aqi.toInt() > 150 && this->forecast[i].aqi.toInt() <= 200){
            this->forecast_aqi_list[i]->setText(u8"重度污染");
            this->forecast_aqi_list[i]->setStyleSheet("color: rgb(255, 0, 0);");
        }
        else{
            this->forecast_aqi_list[i]->setText(u8"严重污染");
            this->forecast_aqi_list[i]->setStyleSheet("color: rgb(170, 0, 0);");
        }
    }

    // 更新今天昨天label
    ui->week0Lb->setText(u8"昨天");
    ui->week1Lb->setText(u8"今天");

}
