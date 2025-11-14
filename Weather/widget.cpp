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
    this->mPos = event->globalPos() - this->pos(); // mPos相当于鼠标在窗口中的位置
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{   
    // 更改窗口位置
    // this->pos() = event->globalPos() - this->mPos;
    this->move(event->globalPos() - this->mPos);
}
