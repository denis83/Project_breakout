// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  block.cpp
//
// Authors: Denis Pelevin/Kevin DiMaria
// 
// Base code that we used was found at 
// http://www.zetcode.com/gui/qt4/breakoutgame/
//
// Submited on 05/04/2013
//
// ///////////////////////////////////////////////////////
#include "block.h"
#include <iostream>


Block::Block(int x, int y) //constructor
{
  image.load("blue.png"); //image for the blocks
  destroyed = FALSE; //boolean to determine if block has been hit or not.
  rect = image.rect();
  rect.translate(x, y); //sets the position for each block.
}

Block::~Block()
{
}

QRect Block::getRect()
{
  return rect;
}

void Block::setRect(QRect rct)
{
  rect = rct;
}

QImage & Block::getImage()
{
  return image; //setting block image.
}

bool Block::isDestroyed()
{
  return destroyed; //boolean to determine destroyed or not.
}

void Block::setDestroyed(bool destr)
{
  destroyed = destr; //setting the boolean
}
