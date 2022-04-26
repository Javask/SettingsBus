#include <QApplication>
#include <QtDBus/QtDBus>
#include "mainwindow.h"
#include "defines.h"
#include <iostream>

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  if (!QDBusConnection::sessionBus().isConnected()) {
    std::cerr << "Cannot connect to the D-Bus session bus.\n"
              << "To start it, run:\n"
              << "\teval `dbus-launch --auto-syntax`" << std::endl;
    return 1;
  }

  MainWindow win = MainWindow();

  win.show();

  return app.exec();
}
