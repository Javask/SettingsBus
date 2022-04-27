#include "DBusServiceClient.h"
#include "defines.h"
#include <stdexcept>
#include <QtDBus>

DBusServiceClient::DBusServiceClient(QObject* parent) : QObject(parent) {
  iface = new QDBusInterface(SERVICE_NAME, "/",
                             "org.example.QtDBus.ComplexPong.Pong",
                             QDBusConnection::sessionBus(), this);
  if (!iface->isValid()) {
    throw std::runtime_error(
        "Could not connect to Service: " +
        QDBusConnection::sessionBus().lastError().message().toStdString());
  }
}

DBusServiceClient::~DBusServiceClient() { delete iface; }

QDBusVariant DBusServiceClient::query(const QString& str) {
  QDBusReply<QDBusVariant> msg = iface->call("query", str);
  if (!msg.isValid()) {
    throw std::runtime_error("DBus Error: " +
                             msg.error().message().toStdString());
  }
  return msg.value();
}

void DBusServiceClient::stopService() { iface->call("stop"); }