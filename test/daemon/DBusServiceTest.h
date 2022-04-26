#pragma once
#include <QtTest/QtTest>

class DBusServiceTest : public QObject {
  Q_OBJECT
 private slots:
  void testCanConnect();
};