// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  paddle.cpp
//
// Authors: Denis Pelevin/Kevin DiMaria
// 
// Base code that we used was found at 
// http://www.zetcode.com/gui/qt4/breakoutgame/
//
// Submited on 05/04/2013
//
// ///////////////////////////////////////////////////////

#include "paddle.h"
#include <iostream>

// Constructor
Paddle::Paddle()
{
  image.load("paddle.png");

  rect = image.rect();
  resetPaddleState();
}

// Destructor
Paddle::~Paddle()
{
}

// Paddle controls (LEFT)
void Paddle::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}
// Paddle controls (RIGHT)
void Paddle::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

// Reset paddle in the middle of the screen
void Paddle::resetPaddleState()
{
  rect.moveTo(125, 360);
}

// rect getter
QRect Paddle::getRect()
{
  return rect;
}

// Image getter
QImage & Paddle::getImage()
{
  return image;
}
