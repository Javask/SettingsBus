#pragma once
#include <QtTest/QtTest>

class DBusServiceTest : public QObject {
  Q_OBJECT
 private slots:
  void testCanConnect();

 public slots:
  void onStop();

 private:
  bool didStop = false;
};