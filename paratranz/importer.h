
#ifndef IMPORTER_H
#define IMPORTER_H

#include <QDir>
#include <QFile>
#include <QObject>

#include "jsondata.h"

class Importer : public QObject
{
    Q_OBJECT
public:
    explicit Importer(QObject *parent = nullptr);
    explicit Importer(const QString &filePath, QObject *parent = nullptr);

    int parse();
    int parse(const QString &filePath);

    void setFilePath(const QString &filePath);

    JsonDataList &data();
    const JsonDataList &data() const;

signals:

private:
    QFile _file;
    QString _fileName;
    QDir _dir;
    bool _isDir;

    JsonDataList _dataList;
};

#endif // IMPORTER_H
