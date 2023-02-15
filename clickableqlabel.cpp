#include "clickableqlabel.h"

#include <qdebug.h>

ClickableQLabel::ClickableQLabel(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent) {}

ClickableQLabel::~ClickableQLabel() {}

void ClickableQLabel::openOrCloseDoor() {
  if (doorOpened) {
    QPixmap door_closed(":/new/images/microwave_door_closed");
    setPixmap(door_closed);
    doorOpened = false;
  } else {
    QPixmap door_open(":/new/images/microwave_door_open");
    setPixmap(door_open);
    doorOpened = true;
  }
}

void ClickableQLabel::open() { qDebug("ClickableQLabel::open()"); }

void ClickableQLabel::close() { qDebug("ClickableQLabel::close()"); }

void ClickableQLabel::mousePressEvent(QMouseEvent *event) {
  openOrCloseDoor();

  // not working/in use
  emit labelClicked();
}
