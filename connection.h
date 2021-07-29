#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QString>
class connection : public QObject
{
    Q_OBJECT
public:
    explicit connection(QObject *parent = nullptr);

signals:
    void show();

public slots:
    void setOrder(QString);
private:
    QString order;
};

#endif // CONNECTION_H
