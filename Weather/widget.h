#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QFile>
#include <QPoint>


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

protected:
    void contextMenuEvent(QContextMenuEvent *menuEvent); // 重写右键菜单事件
    void slot_exitApp(); // 退出程序槽函数
    void mouseMoveEvent(QMouseEvent *event); // 重写鼠标移动事件
    void mousePressEvent(QMouseEvent *event); // 重写鼠标点击事件
};
#endif // WIDGET_H
