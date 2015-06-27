#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    showNotifyButton = ui->showNotifyButton;
    connect(showNotifyButton, SIGNAL(clicked(bool)), this, SLOT(showMessage()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showMessage()
{
//    NotificationWidget *w = new NotificationWidget();
//    w->show();

//    OSDPretty *osd = new OSDPretty(OSDPretty::Mode_Popup);
//    osd->set_fading_enabled(true);
//    QFont font("Tahoma",11);
//    //osd->setOsdFont(font);
//    osd->set_popup_duration(2000);
//    osd->set_fading_enabled(true);

//    osd->SetMessage("name","многомногофждвылмофждвмтдышиамдфотмдлфоимофвримдфловам\nasldjvn",QImage(":/images/face.png"));
//    osd->show();

    QOSD *osd = new QOSD();
    osd->show();
    osd->setScreenAlignment(Qt::AlignCenter);
}
