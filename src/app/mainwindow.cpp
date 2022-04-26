#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include "defines.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  dbusInterface = new DBusService(this);
}

MainWindow::~MainWindow() {
  delete dbusInterface;
  delete ui;
}
