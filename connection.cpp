#include "connection.h"
#include <QDebug>
connection::connection(QObject *parent) : QObject(parent)
{
    connect(this, &connection::setOrder, this, &connection::show);
}

void connection::setOrder(QString order)
{
    this->order = order;
    qDebug() << order;
    emit show();
}
