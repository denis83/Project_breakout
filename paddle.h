// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  paddle.h
//
// Authors: Denis Pelevin/Kevin DiMaria
// 
// Base code that we used was found at 
// http://www.zetcode.com/gui/qt4/breakoutgame/
//
// Submited on 05/04/2013
//
// ///////////////////////////////////////////////////////
#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>

class Paddle
{

  public:
    Paddle();
    ~Paddle();
    void resetPaddleState();
    void moveLeft(int);
    void moveRight(int);
    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;

};

#endif
