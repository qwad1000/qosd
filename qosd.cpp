#include "qosd.h"

const int TimerInterval = 2000;

QOSD::QOSD(QScreen *screen, QWidget *parent) :
    QFrame(parent),
    m_screen(screen)//TODO
{
    /*QHBoxLayout *hLayout = new QHBoxLayout(this);
    QLabel *label = new QLabel("adsf", this);
    hLayout->addWidget(label);
    this->setLayout(hLayout);*/

    setAttribute(Qt::WA_TranslucentBackground, true);

    Qt::WindowFlags flags = Qt::Popup;//Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint;
    setWindowFlags(flags);/*Qt::Popup;//*/

    setStyleSheet("QOSD {"
                  "background: yellow;"
                  "background-clip: border;"
    //              "border: 2px solid green;"
                  "border-radius: 4px;"
                  "}");

    m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    m_timer->setInterval(TimerInterval);
    connect(m_timer, &QTimer::timeout, this, &QOSD::close);
}

Qt::Alignment QOSD::screenAlignment() const
{
    return m_screenAlignment;
}

QScreen *QOSD::screen() const
{
    return m_screen;
}

int QOSD::timerInterval() const
{
    return m_timer->interval();
}

void QOSD::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void QOSD::enterEvent(QEvent *)
{
    if(m_timer->isActive()){
        m_timer->stop();
    }
}

void QOSD::leaveEvent(QEvent *)
{
    if(!m_timer->isActive()){
        m_timer->start();
    }
}

void QOSD::setScreenAlignment(Qt::Alignment screenAlignment)
{
    if (m_screenAlignment == screenAlignment)
        return;

    QFrame::show(); /// crunch for dealing with geometry while widget is not shown
    updateGeometry();
    QFrame::hide();

    m_screenAlignment = screenAlignment;

    int width = geometry().width();
    int height = geometry().height();
    int x = 0, y = 0;

    Qt::Alignment verticalAlignment = screenAlignment & Qt::AlignVertical_Mask;
    if(verticalAlignment == 0){
        verticalAlignment = Qt::AlignTop;
    }
    switch (verticalAlignment) {
    case Qt::AlignTop:
        y = ScreenMargin;
        break;
    case Qt::AlignVCenter:
        y = m_screen->geometry().height()/2 - height/2;
        break;
    case Qt::AlignBottom:
        y = m_screen->geometry().height() - height - ScreenMargin;
        break;
    default:
        qDebug()<<"Can't use this vertical alignment";
        break;
    }

    Qt::Alignment horizontalAlignment = screenAlignment & Qt::AlignHorizontal_Mask;
    if(horizontalAlignment == 0){
        horizontalAlignment = Qt::AlignLeft;
    }
    switch (horizontalAlignment) {
    case Qt::AlignLeft:
        x = ScreenMargin;
        break;
    case Qt::AlignRight:
        x = m_screen->geometry().width() - width - ScreenMargin;
        break;
    case Qt::AlignHCenter:
        x = m_screen->geometry().width()/2 - width/2;
        break;
    default:
        qDebug()<<"Can't use this horizontal alignment";
        break;
    }

    this->setGeometry(x,y,width, height);
}

void QOSD::setScreen(QScreen *screen)
{
    m_screen = screen;
}

void QOSD::show()
{
    m_timer->start();
    QFrame::show();
}

void QOSD::setTimerInterval(int timerInterval)
{
    m_timer->setInterval(timerInterval);
}


