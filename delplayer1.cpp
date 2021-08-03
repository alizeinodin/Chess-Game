#include "delplayer1.h"

DelPlayer1::DelPlayer1(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant DelPlayer1::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex DelPlayer1::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex DelPlayer1::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int DelPlayer1::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int DelPlayer1::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant DelPlayer1::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
