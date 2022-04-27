#pragma once
#include <QObject>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusVariant>

class DBusServiceClient : public QObject {
  Q_OBJECT
 public:
  explicit DBusServiceClient(QObject *parent = nullptr);
  virtual ~DBusServiceClient();

 public slots:
  QDBusVariant query(const QString &str);
  void stopService();

 private:
  QDBusInterface *iface;
};