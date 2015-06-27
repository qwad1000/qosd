#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

#include "notificationwidget.h"
#include "prettyosd/osdpretty.h"
#include "qosd.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void showMessage();
private:
    Ui::Widget *ui;

    QPushButton *showNotifyButton;
};

#endif // WIDGET_H
