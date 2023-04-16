
#ifndef JSONDATA_H
#define JSONDATA_H

#include <QList>

#include "data_global.h"

class DATA_EXPORT JsonData
{
public:
    JsonData();
    JsonData(const JsonData &);
    JsonData(JsonData &&other) noexcept;

    JsonData &operator=(const JsonData &other);
    JsonData &operator=(JsonData &&other) noexcept;

    QString key() const;
    void setKey(const QString &key);

    QString original() const;
    void setOriginal(const QString &original);

    QString translation() const;
    void setTranslation(const QString &translation);

private:
    QString _key;
    QString _original;
    QString _translation;
};

class JsonDataList : public QList<JsonData>
{
public:
    JsonDataList()
        : QList<JsonData>()
    {}

    ~JsonDataList() {}
};

#endif // JSONDATA_H
