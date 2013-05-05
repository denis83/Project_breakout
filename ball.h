#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>

class Ball
{

  public:
    Ball();
    ~Ball();
    void resetBallState();
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    int level;
    bool stuck;
    QImage image;
    QRect rect;

};

#endif
