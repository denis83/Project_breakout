#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "ball.h"
#include "block.h"
#include "paddle.h"
#include <QWidget>
#include <QKeyEvent>

class Breakout : public QWidget
{
  Q_OBJECT

  public:
    Breakout(QWidget *parent = 0);
    ~Breakout();

  protected:

  private:

};

#endif
