#include "qtitledosd.h"

QTitledOSD::QTitledOSD(const QString &title)
{
    osdLayout = new QVBoxLayout(this);

    headerLayout = new QHBoxLayout(this);
    titleLabel = new QLabel(title, this);
    headerLayout->addWidget(titleLabel);
    closeButton = new QToolButton(this);
    closeButton->setText("X");
    connect(closeButton, &QToolButton::clicked, this, &QTitledOSD::close);
    headerLayout->addStretch();
    headerLayout->addWidget(closeButton);

    osdLayout->addLayout(headerLayout);

    footerLayout = new QHBoxLayout(this);
    osdLayout->addLayout(footerLayout);
}

