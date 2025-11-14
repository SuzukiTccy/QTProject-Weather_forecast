/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QLineEdit *cityLineEdit;
    QLabel *dataLb;
    QFrame *hLine_1;
    QFrame *hLine_10;
    QFrame *hLine_11;
    QLabel *label_4;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *flLb;
    QLabel *fxTitleLb;
    QLabel *shiduLb;
    QLabel *flTitleLb;
    QLabel *pm25TitleLb;
    QLabel *shiduTitleLb;
    QLabel *fxLb;
    QLabel *pm25Lb;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *typeIco2Lb;
    QLabel *low2Lb;
    QLabel *typeIco1Lb;
    QLabel *week3Lb;
    QLabel *high3Lb;
    QLabel *week4Lb;
    QLabel *date2Lb;
    QLabel *high4Lb;
    QLabel *low0Lb;
    QLabel *tem3Lb;
    QLabel *quality2Lb;
    QLabel *high5Lb;
    QLabel *curveLb;
    QLabel *week2Lb;
    QLabel *date1Lb;
    QLabel *quality1Lb;
    QLabel *quality4Lb;
    QLabel *date4Lb;
    QLabel *tem5Lb;
    QLabel *tem1Lb;
    QLabel *low1Lb;
    QLabel *low4Lb;
    QLabel *typeIco0Lb;
    QLabel *date5Lb;
    QLabel *low5Lb;
    QLabel *typeIco3Lb;
    QLabel *week1Lb;
    QLabel *typeIco4Lb;
    QLabel *tem2Lb;
    QLabel *high0Lb;
    QLabel *date3Lb;
    QLabel *quality0Lb;
    QLabel *tem4Lb;
    QLabel *high1Lb;
    QLabel *week5Lb;
    QLabel *high2Lb;
    QLabel *quality5Lb;
    QLabel *low3Lb;
    QLabel *tem0Lb;
    QLabel *quality3Lb;
    QLabel *date0Lb;
    QLabel *week0Lb;
    QLabel *typeIco5Lb;
    QLabel *gmTitleLb;
    QLabel *typeIcoLb;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *cityQualIco;
    QLabel *cityQualLb;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *cityLocationIco;
    QLabel *cityLocLb;
    QLabel *cityTemLb;
    QLabel *cityWeaLb;
    QLabel *noticeLb;
    QPushButton *searchBt;
    QLabel *label;
    QPushButton *refreshBt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 450);
        Widget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 800, 450));
        widget->setStyleSheet(QString::fromUtf8("QWidget #widget{\n"
"border-image: url(:/weaUI/weaUI.png);\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: \"Microsoft YaHei\";\n"
"border-radius: 4px;\n"
"background-color: rgba(60, 60, 60, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        cityLineEdit = new QLineEdit(widget);
        cityLineEdit->setObjectName("cityLineEdit");
        cityLineEdit->setEnabled(false);
        cityLineEdit->setGeometry(QRect(570, 10, 171, 31));
        cityLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 1);"));
        dataLb = new QLabel(widget);
        dataLb->setObjectName("dataLb");
        dataLb->setGeometry(QRect(290, 10, 171, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        dataLb->setFont(font);
        dataLb->setStyleSheet(QString::fromUtf8(""));
        dataLb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        hLine_1 = new QFrame(widget);
        hLine_1->setObjectName("hLine_1");
        hLine_1->setGeometry(QRect(10, 48, 781, 1));
        hLine_1->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 0.5);"));
        hLine_1->setFrameShape(QFrame::Shape::HLine);
        hLine_1->setFrameShadow(QFrame::Shadow::Sunken);
        hLine_10 = new QFrame(widget);
        hLine_10->setObjectName("hLine_10");
        hLine_10->setGeometry(QRect(10, 184, 331, 1));
        hLine_10->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 0.5);"));
        hLine_10->setFrameShape(QFrame::Shape::HLine);
        hLine_10->setFrameShadow(QFrame::Shadow::Sunken);
        hLine_11 = new QFrame(widget);
        hLine_11->setObjectName("hLine_11");
        hLine_11->setGeometry(QRect(10, 325, 331, 1));
        hLine_11->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 0.5);"));
        hLine_11->setFrameShape(QFrame::Shape::HLine);
        hLine_11->setFrameShadow(QFrame::Shadow::Sunken);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 10, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200")});
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font: 22pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(85, 255, 0);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 190, 331, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        flLb = new QLabel(gridLayoutWidget);
        flLb->setObjectName("flLb");
        flLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(flLb, 5, 1, 1, 2);

        fxTitleLb = new QLabel(gridLayoutWidget);
        fxTitleLb->setObjectName("fxTitleLb");
        fxTitleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(fxTitleLb, 4, 0, 1, 1);

        shiduLb = new QLabel(gridLayoutWidget);
        shiduLb->setObjectName("shiduLb");
        shiduLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(shiduLb, 2, 1, 1, 2);

        flTitleLb = new QLabel(gridLayoutWidget);
        flTitleLb->setObjectName("flTitleLb");
        flTitleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(flTitleLb, 5, 0, 1, 1);

        pm25TitleLb = new QLabel(gridLayoutWidget);
        pm25TitleLb->setObjectName("pm25TitleLb");
        pm25TitleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(pm25TitleLb, 3, 0, 1, 1);

        shiduTitleLb = new QLabel(gridLayoutWidget);
        shiduTitleLb->setObjectName("shiduTitleLb");
        shiduTitleLb->setStyleSheet(QString::fromUtf8("background-color:rgba(255,255,255,0.3);"));
        shiduTitleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(shiduTitleLb, 2, 0, 1, 1);

        fxLb = new QLabel(gridLayoutWidget);
        fxLb->setObjectName("fxLb");
        fxLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(fxLb, 4, 1, 1, 2);

        pm25Lb = new QLabel(gridLayoutWidget);
        pm25Lb->setObjectName("pm25Lb");
        pm25Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(pm25Lb, 3, 1, 1, 2);

        gridLayoutWidget_2 = new QWidget(widget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(350, 60, 441, 381));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        typeIco2Lb = new QLabel(gridLayoutWidget_2);
        typeIco2Lb->setObjectName("typeIco2Lb");
        typeIco2Lb->setStyleSheet(QString::fromUtf8("image: url(:/day/day/\346\231\264.png);"));
        typeIco2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(typeIco2Lb, 4, 2, 2, 1);

        low2Lb = new QLabel(gridLayoutWidget_2);
        low2Lb->setObjectName("low2Lb");
        low2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(low2Lb, 10, 2, 1, 1);

        typeIco1Lb = new QLabel(gridLayoutWidget_2);
        typeIco1Lb->setObjectName("typeIco1Lb");
        typeIco1Lb->setStyleSheet(QString::fromUtf8("image: url(:/day/day/\345\244\247\346\232\264\351\233\250\345\210\260\347\211\271\345\244\247\346\232\264\351\233\250.png);"));
        typeIco1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(typeIco1Lb, 4, 1, 2, 1);

        week3Lb = new QLabel(gridLayoutWidget_2);
        week3Lb->setObjectName("week3Lb");
        week3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(week3Lb, 0, 3, 1, 1);

        high3Lb = new QLabel(gridLayoutWidget_2);
        high3Lb->setObjectName("high3Lb");
        high3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(high3Lb, 6, 3, 1, 1);

        week4Lb = new QLabel(gridLayoutWidget_2);
        week4Lb->setObjectName("week4Lb");
        week4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(week4Lb, 0, 4, 1, 1);

        date2Lb = new QLabel(gridLayoutWidget_2);
        date2Lb->setObjectName("date2Lb");
        date2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(date2Lb, 1, 2, 1, 1);

        high4Lb = new QLabel(gridLayoutWidget_2);
        high4Lb->setObjectName("high4Lb");
        high4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(high4Lb, 6, 4, 1, 1);

        low0Lb = new QLabel(gridLayoutWidget_2);
        low0Lb->setObjectName("low0Lb");
        low0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(low0Lb, 10, 0, 1, 1);

        tem3Lb = new QLabel(gridLayoutWidget_2);
        tem3Lb->setObjectName("tem3Lb");
        tem3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tem3Lb, 3, 3, 1, 1);

        quality2Lb = new QLabel(gridLayoutWidget_2);
        quality2Lb->setObjectName("quality2Lb");
        quality2Lb->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        quality2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(quality2Lb, 2, 2, 1, 1);

        high5Lb = new QLabel(gridLayoutWidget_2);
        high5Lb->setObjectName("high5Lb");
        high5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(high5Lb, 6, 5, 1, 1);

        curveLb = new QLabel(gridLayoutWidget_2);
        curveLb->setObjectName("curveLb");
        curveLb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(curveLb, 7, 0, 3, 6);

        week2Lb = new QLabel(gridLayoutWidget_2);
        week2Lb->setObjectName("week2Lb");
        week2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(week2Lb, 0, 2, 1, 1);

        date1Lb = new QLabel(gridLayoutWidget_2);
        date1Lb->setObjectName("date1Lb");
        date1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(date1Lb, 1, 1, 1, 1);

        quality1Lb = new QLabel(gridLayoutWidget_2);
        quality1Lb->setObjectName("quality1Lb");
        quality1Lb->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        quality1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(quality1Lb, 2, 1, 1, 1);

        quality4Lb = new QLabel(gridLayoutWidget_2);
        quality4Lb->setObjectName("quality4Lb");
        quality4Lb->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        quality4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(quality4Lb, 2, 4, 1, 1);

        date4Lb = new QLabel(gridLayoutWidget_2);
        date4Lb->setObjectName("date4Lb");
        date4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(date4Lb, 1, 4, 1, 1);

        tem5Lb = new QLabel(gridLayoutWidget_2);
        tem5Lb->setObjectName("tem5Lb");
        tem5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tem5Lb, 3, 5, 1, 1);

        tem1Lb = new QLabel(gridLayoutWidget_2);
        tem1Lb->setObjectName("tem1Lb");
        tem1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tem1Lb, 3, 1, 1, 1);

        low1Lb = new QLabel(gridLayoutWidget_2);
        low1Lb->setObjectName("low1Lb");
        low1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(low1Lb, 10, 1, 1, 1);

        low4Lb = new QLabel(gridLayoutWidget_2);
        low4Lb->setObjectName("low4Lb");
        low4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(low4Lb, 10, 4, 1, 1);

        typeIco0Lb = new QLabel(gridLayoutWidget_2);
        typeIco0Lb->setObjectName("typeIco0Lb");
        typeIco0Lb->setStyleSheet(QString::fromUtf8("image: url(:/day/day/\345\260\217\351\233\250.png);"));
        typeIco0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(typeIco0Lb, 4, 0, 2, 1);

        date5Lb = new QLabel(gridLayoutWidget_2);
        date5Lb->setObjectName("date5Lb");
        date5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(date5Lb, 1, 5, 1, 1);

        low5Lb = new QLabel(gridLayoutWidget_2);
        low5Lb->setObjectName("low5Lb");
        low5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(low5Lb, 10, 5, 1, 1);

        typeIco3Lb = new QLabel(gridLayoutWidget_2);
        typeIco3Lb->setObjectName("typeIco3Lb");
        typeIco3Lb->setStyleSheet(QString::fromUtf8("image: url(:/night/night/\351\233\276.png);"));
        typeIco3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(typeIco3Lb, 4, 3, 2, 1);

        week1Lb = new QLabel(gridLayoutWidget_2);
        week1Lb->setObjectName("week1Lb");
        week1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(week1Lb, 0, 1, 1, 1);

        typeIco4Lb = new QLabel(gridLayoutWidget_2);
        typeIco4Lb->setObjectName("typeIco4Lb");
        typeIco4Lb->setStyleSheet(QString::fromUtf8("image: url(:/day/day/\351\230\265\351\233\250.png);"));
        typeIco4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(typeIco4Lb, 4, 4, 2, 1);

        tem2Lb = new QLabel(gridLayoutWidget_2);
        tem2Lb->setObjectName("tem2Lb");
        tem2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tem2Lb, 3, 2, 1, 1);

        high0Lb = new QLabel(gridLayoutWidget_2);
        high0Lb->setObjectName("high0Lb");
        high0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(high0Lb, 6, 0, 1, 1);

        date3Lb = new QLabel(gridLayoutWidget_2);
        date3Lb->setObjectName("date3Lb");
        date3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(date3Lb, 1, 3, 1, 1);

        quality0Lb = new QLabel(gridLayoutWidget_2);
        quality0Lb->setObjectName("quality0Lb");
        quality0Lb->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        quality0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(quality0Lb, 2, 0, 1, 1);

        tem4Lb = new QLabel(gridLayoutWidget_2);
        tem4Lb->setObjectName("tem4Lb");
        tem4Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tem4Lb, 3, 4, 1, 1);

        high1Lb = new QLabel(gridLayoutWidget_2);
        high1Lb->setObjectName("high1Lb");
        high1Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(high1Lb, 6, 1, 1, 1);

        week5Lb = new QLabel(gridLayoutWidget_2);
        week5Lb->setObjectName("week5Lb");
        week5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(week5Lb, 0, 5, 1, 1);

        high2Lb = new QLabel(gridLayoutWidget_2);
        high2Lb->setObjectName("high2Lb");
        high2Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(high2Lb, 6, 2, 1, 1);

        quality5Lb = new QLabel(gridLayoutWidget_2);
        quality5Lb->setObjectName("quality5Lb");
        quality5Lb->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        quality5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(quality5Lb, 2, 5, 1, 1);

        low3Lb = new QLabel(gridLayoutWidget_2);
        low3Lb->setObjectName("low3Lb");
        low3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(low3Lb, 10, 3, 1, 1);

        tem0Lb = new QLabel(gridLayoutWidget_2);
        tem0Lb->setObjectName("tem0Lb");
        tem0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(tem0Lb, 3, 0, 1, 1);

        quality3Lb = new QLabel(gridLayoutWidget_2);
        quality3Lb->setObjectName("quality3Lb");
        quality3Lb->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 0);"));
        quality3Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(quality3Lb, 2, 3, 1, 1);

        date0Lb = new QLabel(gridLayoutWidget_2);
        date0Lb->setObjectName("date0Lb");
        date0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(date0Lb, 1, 0, 1, 1);

        week0Lb = new QLabel(gridLayoutWidget_2);
        week0Lb->setObjectName("week0Lb");
        week0Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(week0Lb, 0, 0, 1, 1);

        typeIco5Lb = new QLabel(gridLayoutWidget_2);
        typeIco5Lb->setObjectName("typeIco5Lb");
        typeIco5Lb->setStyleSheet(QString::fromUtf8("image: url(:/day/day/\345\274\272\346\262\231\345\260\230\346\232\264.png);"));
        typeIco5Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(typeIco5Lb, 4, 5, 2, 1);

        gmTitleLb = new QLabel(widget);
        gmTitleLb->setObjectName("gmTitleLb");
        gmTitleLb->setGeometry(QRect(10, 330, 21, 111));
        gmTitleLb->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        gmTitleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        typeIcoLb = new QLabel(widget);
        typeIcoLb->setObjectName("typeIcoLb");
        typeIcoLb->setGeometry(QRect(220, 60, 121, 111));
        typeIcoLb->setStyleSheet(QString::fromUtf8("border-image: url(:/day/day/\346\231\264.png);\n"
"background-color: rgba(60,60,60,0);"));
        gridLayoutWidget_3 = new QWidget(widget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(20, 60, 51, 21));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        cityQualIco = new QLabel(gridLayoutWidget_3);
        cityQualIco->setObjectName("cityQualIco");
        cityQualIco->setStyleSheet(QString::fromUtf8("border-image:url(:/weatherIco/leaf.ico)"));
        cityQualIco->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_3->addWidget(cityQualIco, 0, 0, 1, 1);

        cityQualLb = new QLabel(gridLayoutWidget_3);
        cityQualLb->setObjectName("cityQualLb");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        cityQualLb->setFont(font2);

        gridLayout_3->addWidget(cityQualLb, 0, 1, 1, 1);

        gridLayoutWidget_4 = new QWidget(widget);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(150, 50, 61, 31));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        cityLocationIco = new QLabel(gridLayoutWidget_4);
        cityLocationIco->setObjectName("cityLocationIco");
        cityLocationIco->setStyleSheet(QString::fromUtf8("border-image:url(:/weatherIco/location.ico)"));
        cityLocationIco->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(cityLocationIco, 0, 0, 1, 1);

        cityLocLb = new QLabel(gridLayoutWidget_4);
        cityLocLb->setObjectName("cityLocLb");
        cityLocLb->setFont(font2);

        gridLayout_4->addWidget(cityLocLb, 0, 1, 1, 1);

        cityTemLb = new QLabel(widget);
        cityTemLb->setObjectName("cityTemLb");
        cityTemLb->setGeometry(QRect(50, 80, 121, 81));
        cityTemLb->setStyleSheet(QString::fromUtf8("color:rgba(255,255,255,1);\n"
"font: 42pt;"));
        cityTemLb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cityWeaLb = new QLabel(widget);
        cityWeaLb->setObjectName("cityWeaLb");
        cityWeaLb->setGeometry(QRect(160, 130, 41, 16));
        cityWeaLb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        noticeLb = new QLabel(widget);
        noticeLb->setObjectName("noticeLb");
        noticeLb->setGeometry(QRect(10, 160, 211, 16));
        searchBt = new QPushButton(widget);
        searchBt->setObjectName("searchBt");
        searchBt->setGeometry(QRect(710, 10, 31, 32));
        searchBt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchBt->setStyleSheet(QString::fromUtf8("border-image:url(:/weatherIco/search.ico);"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 340, 141, 91));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        refreshBt = new QPushButton(widget);
        refreshBt->setObjectName("refreshBt");
        refreshBt->setGeometry(QRect(750, 10, 31, 31));
        refreshBt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refreshBt->setStyleSheet(QString::fromUtf8("border-image:url(:/weatherIco/refresh.ico)"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        dataLb->setText(QCoreApplication::translate("Widget", "2025-11-13", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\244\251\346\260\224\351\242\204\346\212\245", nullptr));
        flLb->setText(QCoreApplication::translate("Widget", "4\347\272\247", nullptr));
        fxTitleLb->setText(QCoreApplication::translate("Widget", "\351\243\216\345\220\221", nullptr));
        shiduLb->setText(QCoreApplication::translate("Widget", "64%", nullptr));
        flTitleLb->setText(QCoreApplication::translate("Widget", "\351\243\216\345\212\233", nullptr));
        pm25TitleLb->setText(QCoreApplication::translate("Widget", "PM2.5", nullptr));
        shiduTitleLb->setText(QCoreApplication::translate("Widget", "\346\271\277\345\272\246", nullptr));
        fxLb->setText(QCoreApplication::translate("Widget", "\345\214\227\351\243\216", nullptr));
        pm25Lb->setText(QCoreApplication::translate("Widget", "26", nullptr));
        typeIco2Lb->setText(QString());
        low2Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        typeIco1Lb->setText(QString());
        week3Lb->setText(QCoreApplication::translate("Widget", "\346\230\237\346\234\237\345\205\255", nullptr));
        high3Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        week4Lb->setText(QCoreApplication::translate("Widget", "\346\230\237\346\234\237\346\227\245", nullptr));
        date2Lb->setText(QCoreApplication::translate("Widget", "08", nullptr));
        high4Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        low0Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        tem3Lb->setText(QCoreApplication::translate("Widget", "\345\244\232\344\272\221", nullptr));
        quality2Lb->setText(QCoreApplication::translate("Widget", "\344\274\230\350\264\250", nullptr));
        high5Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        curveLb->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        week2Lb->setText(QCoreApplication::translate("Widget", "\346\230\237\346\234\237\344\272\224", nullptr));
        date1Lb->setText(QCoreApplication::translate("Widget", "07", nullptr));
        quality1Lb->setText(QCoreApplication::translate("Widget", "\344\274\230\350\264\250", nullptr));
        quality4Lb->setText(QCoreApplication::translate("Widget", "\350\275\273\345\272\246\346\261\241\346\237\223", nullptr));
        date4Lb->setText(QCoreApplication::translate("Widget", "10", nullptr));
        tem5Lb->setText(QCoreApplication::translate("Widget", "\346\231\264", nullptr));
        tem1Lb->setText(QCoreApplication::translate("Widget", "\351\233\250\345\244\271\351\233\252", nullptr));
        low1Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        low4Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        typeIco0Lb->setText(QString());
        date5Lb->setText(QCoreApplication::translate("Widget", "11", nullptr));
        low5Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        typeIco3Lb->setText(QString());
        week1Lb->setText(QCoreApplication::translate("Widget", "\344\273\212\345\244\251", nullptr));
        typeIco4Lb->setText(QString());
        tem2Lb->setText(QCoreApplication::translate("Widget", "\346\231\264", nullptr));
        high0Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        date3Lb->setText(QCoreApplication::translate("Widget", "09", nullptr));
        quality0Lb->setText(QCoreApplication::translate("Widget", "\350\275\273\345\272\246\346\261\241\346\237\223", nullptr));
        tem4Lb->setText(QCoreApplication::translate("Widget", "\351\230\264", nullptr));
        high1Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        week5Lb->setText(QCoreApplication::translate("Widget", "\346\230\237\346\234\237\344\270\200", nullptr));
        high2Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        quality5Lb->setText(QCoreApplication::translate("Widget", "\350\275\273\345\272\246\346\261\241\346\237\223", nullptr));
        low3Lb->setText(QCoreApplication::translate("Widget", "3\342\204\203", nullptr));
        tem0Lb->setText(QCoreApplication::translate("Widget", "\345\260\217\351\233\250", nullptr));
        quality3Lb->setText(QCoreApplication::translate("Widget", "\350\211\257\345\245\275", nullptr));
        date0Lb->setText(QCoreApplication::translate("Widget", "06", nullptr));
        week0Lb->setText(QCoreApplication::translate("Widget", "\346\230\250\345\244\251", nullptr));
        typeIco5Lb->setText(QString());
        gmTitleLb->setText(QCoreApplication::translate("Widget", "\346\204\237\n"
"\345\206\222\n"
"\346\214\207\n"
"\346\225\260", nullptr));
        typeIcoLb->setText(QString());
        cityQualIco->setText(QString());
        cityQualLb->setText(QCoreApplication::translate("Widget", "\344\274\230", nullptr));
        cityLocationIco->setText(QString());
        cityLocLb->setText(QCoreApplication::translate("Widget", "\346\267\261\345\234\263\345\270\202", nullptr));
        cityTemLb->setText(QCoreApplication::translate("Widget", "25\342\204\203", nullptr));
        cityWeaLb->setText(QCoreApplication::translate("Widget", "\346\231\264", nullptr));
        noticeLb->setText(QCoreApplication::translate("Widget", "\351\201\223\350\267\257\346\271\277\346\273\221\357\274\214", nullptr));
        searchBt->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "\345\273\272\350\256\256", nullptr));
        refreshBt->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
