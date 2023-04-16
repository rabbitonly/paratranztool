
#ifndef EXPORTER_H
#define EXPORTER_H


#include <QObject>


class Exporter : public QObject
{
    Q_OBJECT
public:
    explicit Exporter(QObject *parent = nullptr);

signals:

};

#endif // EXPORTER_H
