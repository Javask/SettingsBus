#include <QApplication>
#include "defines.h"
#include "DBusDaemon.h"
#include <iostream>
#include <QtDBus/QtDBus>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  if (!QDBusConnection::sessionBus().isConnected()) {
    std::cerr << "Cannot connect to the D-Bus session bus.\n"
              << "To start it, run:\n"
              << "\teval `dbus-launch --auto-syntax`" << std::endl;
    return 1;
  }

  auto service = DBusDaemon(&app);
  return app.exec();
}