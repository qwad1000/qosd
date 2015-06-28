#ifndef QOSD_H
#define QOSD_H

#include <QWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QScreen>
#include <QTimer>
#include <QDebug>
#include <QGuiApplication>
#include <QStyleOption>
#include <QStylePainter>

class QOSD : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(Qt::Alignment screenAlignment READ screenAlignment WRITE setScreenAlignment)
    Q_PROPERTY(QScreen *screen READ screen WRITE setScreen)
    const int ScreenMargin = 0;

public:
    explicit QOSD(QScreen *screen = QGuiApplication::screens().first(), QWidget *parent = 0);

    Qt::Alignment screenAlignment() const;

    QScreen *screen() const;

protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

public slots:
    void setScreenAlignment(Qt::Alignment screenAlignment);
    void setScreen(QScreen *screen);
    void show();

private:
    Qt::Alignment m_screenAlignment;
    QScreen *m_screen;
    QTimer *m_timer;
};

#endif // QOSD_H
