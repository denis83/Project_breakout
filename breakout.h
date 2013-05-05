// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  breakout.h
//
// Authors: Denis Pelevin/Kevin DiMaria
//
// Submited on 05/04/2013
//
// ///////////////////////////////////////////////////////
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
    void paintEvent(QPaintEvent * event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();
    void checkLevel();
    void nextLevel();

  private:
    int x;
    int timerId;
    int level;
    int score;
    Ball *ball;
    Paddle *paddle;
    Block * bricks[30];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;

};

#endif
