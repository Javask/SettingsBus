#pragma once
#include <QObject>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusVariant>
#include <QtDBus/QDBusServiceWatcher>
#include "defines.h"
#include <QObject>

class DBusService : public QDBusAbstractAdaptor {
  Q_OBJECT
  Q_CLASSINFO("D-Bus Service", SERVICE_NAME)

 public:
  explicit DBusService(QObject* parent = nullptr);
  virtual ~DBusService();

 public slots:
  QDBusVariant query(const QString& query);
  void stop();

 signals:
  void onStop();
};