#include "DBusDaemon.h"
#include <QtDBus>
#include <QDebug>

DBusDaemon::DBusDaemon(QObject* parent) : QObject(parent) {
  service = new DBusService(this);

  watcher = new QDBusServiceWatcher(SERVICE_NAME, QDBusConnection::sessionBus(),
                                    QDBusServiceWatcher::WatchForRegistration);
  connect(watcher, &QDBusServiceWatcher::serviceRegistered, this,
          &DBusDaemon::onServiceStart);
  connect(watcher, &QDBusServiceWatcher::serviceUnregistered, this,
          &DBusDaemon::onServiceStop);
}
DBusDaemon::~DBusDaemon() {
  delete watcher;
  delete service;
}

void DBusDaemon::aboutToQuit() {}

void DBusDaemon::onServiceStart(const QString& name) {
  qDebug() << "Service registered: " << name << "\n";
}

void DBusDaemon::onServiceStop(const QString& name) {
  qDebug() << "Service unregistered: " << name << "\n";
}