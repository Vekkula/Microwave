#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ClickableQLabel.h>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <qlcdnumber.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  QLCDNumber *microwaveTimer;
  ClickableQLabel *doorLabel;
  QPushButton *doorButton;

private:
  QString timerNumber = "";
  QTimer timer;

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void changeTimer(QString number);
  void startTimer();

private slots:
  void doorClicked();

  void on_doorButton_clicked();

  void on_pushButton_enter_clicked();

  void on_pushButton_reset_clicked();

  void on_pushButton_0_clicked();

  void on_pushButton_9_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_1_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
