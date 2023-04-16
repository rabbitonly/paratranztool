
#include "importer.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

Importer::Importer(QObject *parent)
    : QObject{parent}
    , _fileName("")
    , _isDir(false)
{}

Importer::Importer(const QString &filePath, QObject *parent)
    : QObject{parent}
    , _isDir(false)
{
    QFileInfo fi(filePath);
    if (!fi.exists()) {
        return;
    }

    if (fi.isFile()) {
        _fileName = filePath;
        _file.setFileName(filePath);
    } else if (fi.isDir()) {
        _isDir = true;
    }

    _dir.setPath(fi.path());
}

int Importer::parse()
{
    if (_fileName.isEmpty()) {
        return -1;
    }

    return parse(_fileName);
}

int Importer::parse(const QString &filePath)
{
    QFileInfo fi(filePath);
    if (!fi.exists()) {
        return -1;
    }

    if (_file.isOpen()) {
        _file.close();
    }

    if (fi.isFile()) {
        _fileName = filePath;
        _file.setFileName(filePath);
    } else if (fi.isDir()) {
        _isDir = true;
    }

    _dir.setPath(fi.path());

    if (fi.isFile()) {
        _file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray jsonData = _file.readAll();
        _file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

        if (jsonDoc.isNull()) {
            qDebug() << "Failed to create JSON document.";
            return -1;
        }

        if (!jsonDoc.isObject()) {
            qDebug() << "JSON is not an object.";
            return -1;
        } else if (jsonDoc.isArray()) {
        }
    }

    return 0;
}

void Importer::setFilePath(const QString &filePath)
{
    QFileInfo fi(filePath);
    if (!fi.exists()) {
        return;
    }

    if (_file.isOpen()) {
        _file.close();
    }

    if (fi.isFile()) {
        _fileName = filePath;
        _file.setFileName(filePath);
    } else if (fi.isDir()) {
        _isDir = true;
    }

    _dir.setPath(fi.path());
}

JsonDataList &Importer::data()
{
    return _dataList;
}

const JsonDataList &Importer::data() const
{
    return _dataList;
}
