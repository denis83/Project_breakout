#include "ball.h"
#include <iostream>

Ball::Ball()
{

  xdir = 1.5;
  ydir = -1.5;

  image.load("bball.png");

  rect = image.rect();
  resetBallState();

}

Ball::~Ball() {
  std::cout << ("Ball deleted\n");
}


void Ball::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() == 0) {
    xdir = 1.5;
  }

  if (rect.right() == 300) {
    xdir = -1.5;
  }

  if (rect.top() == 0) {
    ydir = 1.5;
  }
}

void Ball::resetBallState()
{
  rect.moveTo(145, 350);
}

void Ball::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Ball::moveTop(int top)
{
  rect.moveTop(top);
}

void Ball::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Ball::moveRight(int right)
{
  rect.moveRight(right);
}

void Ball::setXDir(int x)
{
  xdir = x;
}

void Ball::setYDir(int y)
{
  ydir = y;
}

int Ball::getXDir()
{
  return xdir;
}

int Ball::getYDir()
{
  return ydir;
}

QRect Ball::getRect()
{
  return rect;
}

QImage & Ball::getImage()
{
  return image;
}
