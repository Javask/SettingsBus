#pragma once
#include <QObject>
#include "DBusService.h"
#include <QtDBus/QDBusServiceWatcher>

class DBusDaemon : public QObject {
  Q_OBJECT
 public:
  DBusDaemon(QObject* parent = nullptr);
  ~DBusDaemon();

 public slots:
  void aboutToQuit();
  void onServiceStart(const QString& name);
  void onServiceStop(const QString& name);

 private:
  DBusService* service;
  QDBusServiceWatcher* watcher;
};