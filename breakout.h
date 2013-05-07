// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  breakout.h
//
// Authors: Denis Pelevin/Kevin DiMaria
// 
// Base code that we used was found at 
// http://www.zetcode.com/gui/qt4/breakoutgame/
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
    void readInLevels();
    void setLevel();

  private:
    int x;
    int timerId;
    int level;
    int numOfLevels;
    int score;
    int count;
    QStringList lvlList;
    QImage backGround;
    QImage defeatImage;
    QImage victoryImage;
    Ball *ball;
    Paddle *paddle;
    Block * bricks[60];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;

};

#endif
