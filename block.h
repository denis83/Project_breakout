#ifndef BLOCK_H
#define BLOCK_H

#include <QImage>
#include <QRect>

class Block
{
  public:
    Block(int, int);
    ~Block();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    int position;
    bool destroyed;

};

#endif
