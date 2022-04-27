#include "DBusService.h"
#include <stdexcept>
#include <QtDBus/QtDBus>
#include <iostream>
#include <QApplication>

DBusService::DBusService(QObject* parent) : QDBusAbstractAdaptor(parent) {
  QDBusConnection::sessionBus().registerObject("/", parent);
  if (!QDBusConnection::sessionBus().registerService(SERVICE_NAME)) {
    throw std::runtime_error(
        "Could not register DBus-Service: " +
        QDBusConnection::sessionBus().lastError().message().toStdString());
  }
}

DBusService::~DBusService() {}

QDBusVariant DBusService::query(const QString& query) {
  return QDBusVariant(query);
}

void DBusService::stop() { emit onStop(); }