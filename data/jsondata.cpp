
#include "jsondata.h"

JsonData::JsonData() {}

JsonData::JsonData(const JsonData &other)
{
    _key = other._key;
    _original = other._original;
    _translation = other._translation;
}

JsonData::JsonData(JsonData &&other) noexcept
{
    _key = std::move(other._key);
    _original = std::move(other._original);
    _translation = std::move(other._translation);
}

JsonData &JsonData::operator=(const JsonData &other)
{
    if (this != &other) {
        _key = other._key;
        _original = other._original;
        _translation = other._translation;
    }
    return *this;
}

JsonData &JsonData::operator=(JsonData &&other) noexcept
{
    if (this != &other) {
        _key = std::move(other._key);
        _original = std::move(other._original);
        _translation = std::move(other._translation);
    }
    return *this;
}

QString JsonData::key() const
{
    return _key;
}

void JsonData::setKey(const QString &key)
{
    if (_key != key) {
        _key = key;
    }
}

QString JsonData::original() const
{
    return _original;
}

void JsonData::setOriginal(const QString &original)
{
    if (_original != original) {
        _original = original;
    }
}
QString JsonData::translation() const
{
    return _translation;
}

void JsonData::setTranslation(const QString &translation)
{
    if (_translation != translation) {
        _translation = translation;
    }
}
