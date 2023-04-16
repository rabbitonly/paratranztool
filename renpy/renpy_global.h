
#ifndef RENPY_GLOBAL_H
#define RENPY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RENPY_LIBRARY)
#  define RENPY_EXPORT Q_DECL_EXPORT
#else
#  define RENPY_EXPORT Q_DECL_IMPORT
#endif

#endif // RENPY_GLOBAL_H
