#ifndef QTITLEDOSD_H
#define QTITLEDOSD_H

#include <QLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QToolButton>

#include "qosd.h"


class QTitledOSD : public QOSD
{
public:
    QTitledOSD(const QString &title);

private:
    QVBoxLayout *osdLayout;
    QHBoxLayout *headerLayout;
    QHBoxLayout *footerLayout;
    QLayout *mainLayout;

    QLabel *titleLabel;
    QToolButton *closeButton;
};

#endif // QTITLEDOSD_H
