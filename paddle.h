// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  paddle.h
//
// Authors: Denis Pelevin/Kevin DiMaria
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
