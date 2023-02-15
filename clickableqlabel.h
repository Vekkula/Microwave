#ifndef CLICKABLEQLABEL_H
#define CLICKABLEQLABEL_H

#include <QLabel>
#include <QObject>
#include <Qt>

class ClickableQLabel : public QLabel {
  Q_OBJECT
public:
  bool doorOpened = false;

public:
  ClickableQLabel(QWidget *parent = Q_NULLPTR,
                  Qt::WindowFlags f = Qt::WindowFlags());
  ~ClickableQLabel();
  void openOrCloseDoor();

signals:
  void labelClicked();

public slots:
  void open();
  void close();

protected:
  void mousePressEvent(QMouseEvent *event);
};

#endif // CLICKABLEQLABEL_H
