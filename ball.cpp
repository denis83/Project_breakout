//Kevin DiMaria and Denis Pelevin
#include "ball.h"
#include <iostream>

Ball::Ball()
{

  xdir = 1.5;//X-Velocity
  ydir = -1.5;//Y-Velocity

  image.load("bball.png");

  rect = image.rect(); //setting the image for the block
  resetBallState(); //set ball to starting position

}

Ball::~Ball() {
  std::cout << ("Ball deleted\n");//ball is successfully deleted.
}


void Ball::autoMove()
{
  rect.translate(xdir, ydir); //setting velocity for the ball.

  if (rect.left() == 0) {
    xdir = 1.5; //if ball hits the left wall, go right.
  }

  if (rect.right() == 300) {
    xdir = -1.5; //if ball hits the right wall, go left.
  }

  if (rect.top() == 0) {
    ydir = 1.5; //if ball hits the ceiling, go down.
  }
}

void Ball::resetBallState()
{
  rect.moveTo(145, 350);//starting position
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
  return image; //returns image for ball
}
