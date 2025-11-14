#ifndef WEATHERTOOL_H
#define WEATHERTOOL_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

#include <map>
#include <QFile> //读取文件
#include <QCoreApplication> //获取程序路径
#include <QDir> //获取文件路径

class WeatherTool{
private:
    std::map<QString, QString> m_mapCity2Code;

public:
    WeatherTool(){
        // 获取可执行文件的绝对路径
        QDir appDir(QCoreApplication::applicationDirPath());
        // 创建错误信息收集对象
        QJsonParseError err;

        // 构建文件所在路径
        #ifdef Q_OS_MAC
            if (appDir.dirName() == "MacOS"){
                // 在.app/MacOS目录中，需要向上到Resources目录
                appDir.cdUp();
                appDir.cdUp();
                appDir.cd("Resources");
                QString fileName = appDir.absoluteFilePath("citycode-2019-08-23.json");
            }else{
                QString fileName = appDir.absoluteFilePath("../../Weather/citycode-2019-08-23.json");
            }
        #else
            QString fileName = appDir.absoluteFilePath("../../Weather/citycode-2019-08-23.json");
        #endif
        std::cout << "fileName: " << fileName.toStdString() << std::endl;
        
        // 读取文件内容
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray json = file.readAll();
        file.close();

        // 读取Json数据
        QJsonDocument jsonDoc = QJsonDocument::fromJson(json, &err);
        // 获取城市列表数组
        QJsonArray citys = jsonDoc.array();
        // 遍历城市列表
        for(int i = 0; i < citys.size(); ++i){
            QString code = citys.at(i).toObject().value("city_code").toString();
            QString city = citys.at(i).toObject().value("city_name").toString();
            // 省份的code是空的，所以城市代码长度大于0的都可以添加到map中
            if(code.size() > 0){
                m_mapCity2Code.insert(std::pair<QString, QString>(city, code));
            }
        }
    }

    // 重载操作符["city"], 根据城市名称直接得到城市代码：
    QString operator[](const QString& city){
        std::map<QString, QString>::iterator it = m_mapCity2Code.find(city); // 第一轮查找城市名
        if(it == m_mapCity2Code.end()){
            //第二轮查找，搜索城市后带“市”字
            it = m_mapCity2Code.find(city + u8"市");
        }
        if(it == m_mapCity2Code.end()){
            //第三轮查找，搜索城市名后带县字
            it = m_mapCity2Code.find(city+u8"县");
        }
        if(it != m_mapCity2Code.end()){
            //找到直接返回城市代码
            return it->second;
        }
        // 没找到返回9个0
        return "000000000";
    }
};

#endif // WEATHERTOOL_H



