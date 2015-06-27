#include "notificationwidget.h"

NotificationWidget::NotificationWidget(QWidget *parent) :
    QWidget(parent),
    popupInterval(2000)
{
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    QLabel *label = new QLabel("adsf", this);
    hLayout->addWidget(label);
    this->setLayout(hLayout);

    setWindowFlags(Qt::Popup);

    popupTimer = new QTimer(this);
    popupTimer->setSingleShot(true);
    popupTimer->setInterval(popupInterval);
    connect(popupTimer, &QTimer::timeout, this, &NotificationWidget::close);
}

void NotificationWidget::show()
{
    popupTimer->start();
    QWidget::show();
}

