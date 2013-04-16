#include "block.h"
#include <iostream>

Block::Block(int x, int y)
{
  image.load("block.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x, y);
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
  return image;
}

bool Block::isDestroyed()
{
  return destroyed;
}

void Block::setDestroyed(bool destr)
{
  destroyed = destr;
}
