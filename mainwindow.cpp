#include "mainwindow.h"

#include "QDebug"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  doorButton = ui->doorButton;
  doorLabel = ui->Microwave_door_label;
  microwaveTimer = ui->microwaveTimer;

  // connect(ui->pushButton_enter, &QPushButton::clicked, this,
  //         &MainWindow::on_pushButton_enter_clicked);

  // is this needed?
  connect(doorLabel, &ClickableQLabel::labelClicked, this,
          &MainWindow::doorClicked);
}

MainWindow::~MainWindow() {
  delete doorButton;
  delete doorLabel;
  delete ui;
}

void MainWindow::changeTimer(QString number) {
  if (timerNumber == "0") {
    timerNumber = number;
  } else {
    timerNumber.append(number);
  }
  microwaveTimer->display(timerNumber);
}

void MainWindow::startTimer() {
  // TODO maker timer
  // timer = new QTimer();
}

void MainWindow::doorClicked() { qDebug("MainWindow::doorClicked()"); }

void MainWindow::on_doorButton_clicked() { doorLabel->openOrCloseDoor(); }

void MainWindow::on_pushButton_enter_clicked() {
  qDebug("MainWindow::on_pushButton_enter_clicked()");

  microwaveTimer->display(timerNumber);
  startTimer();
}

void MainWindow::on_pushButton_reset_clicked() {
  timerNumber = "";
  microwaveTimer->display("0");
}

void MainWindow::on_pushButton_0_clicked() {
  if (timerNumber == "0") {
    microwaveTimer->display(timerNumber);
  } else if (timerNumber.length() >= 1) {
    timerNumber.append("0");
    microwaveTimer->display(timerNumber);
  } else if (timerNumber.isEmpty()) {
    timerNumber.append("0");
    microwaveTimer->display(timerNumber);
  }
}

void MainWindow::on_pushButton_9_clicked() { changeTimer("9"); }

void MainWindow::on_pushButton_8_clicked() { changeTimer("8"); }

void MainWindow::on_pushButton_7_clicked() { changeTimer("7"); }

void MainWindow::on_pushButton_6_clicked() { changeTimer("6"); }

void MainWindow::on_pushButton_5_clicked() { changeTimer("5"); }

void MainWindow::on_pushButton_4_clicked() { changeTimer("4"); }

void MainWindow::on_pushButton_3_clicked() { changeTimer("3"); }

void MainWindow::on_pushButton_2_clicked() { changeTimer("2"); }

void MainWindow::on_pushButton_1_clicked() { changeTimer("1"); }
