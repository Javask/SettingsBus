#include "DBusServiceTest.h"
#include "DBusServiceClient.h"
#include "DBusService.h"
#include <QtDBus>
#include "defines.h"
void DBusServiceTest::testCanConnect() {
  auto svc = DBusService(this);
  auto client = DBusServiceClient(this);
  client.stopService();
  // QVERIFY(didStop);
}

void DBusServiceTest::onStop() { didStop = true; }

QTEST_MAIN(DBusServiceTest)