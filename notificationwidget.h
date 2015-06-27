#ifndef NOTIFICATIONWIDGET_H
#define NOTIFICATIONWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QTimer>

class NotificationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NotificationWidget(QWidget *parent = 0);

signals:

public slots:
    void show();
private:
    QTimer *popupTimer;
    int popupInterval;
};

#endif // NOTIFICATIONWIDGET_H
