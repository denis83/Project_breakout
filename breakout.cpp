// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  breakout.cpp
//
// Authors: Denis Pelevin/Kevin DiMaria
// 
// Base code that we used was found at 
// http://www.zetcode.com/gui/qt4/breakoutgame/
//
// Submited on 05/04/2013
//
// ///////////////////////////////////////////////////////

//This class provides main game controls.
//This is also main widget class

#include "breakout.h"
#include <QPainter>
#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>

// Constructor
Breakout::Breakout(QWidget *parent)
    : QWidget(parent)
{

  // Reset game flow control flags
  x = 0;
  count=0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  ball = new Ball();
  paddle = new Paddle();
  //reset the level and the score
  level = 1;
  score = 0;
  // Initiate level check and start of the game
  readInLevels();
  checkLevel();
}

// Destructor
Breakout::~Breakout() {
 delete ball;
 delete paddle;
 for (int i=0; i<60; i++) {
   delete bricks[i];
 }
}

// Checks level. Sets up the brick layout according to level number
void Breakout::checkLevel()
{
    ball->resetBallState();
    paddle->resetPaddleState();

    // Layout for level 1. Transition to level 2.
    if(level == 1)
    {
        setLevel();
        level++;
        nextLevel();
        level--;
    }
    else if (level <= numOfLevels)
    {
        setLevel();
        nextLevel();

    }
    else victory(); // Victory screen
}

void Breakout::readInLevels()
{
    QFile levelSetup("lvl.config");
    levelSetup.open(QIODevice::ReadOnly);

    QTextStream readFile(&levelSetup);

    // read line by line and insert into a QStringList
    while (!readFile.atEnd())
    {
        lvlList << readFile.readLine();
    }

    levelSetup.close();

    QString imageLine = lvlList[0];

    QString vicImStr = imageLine.split(" ")[0];
    QString defImStr = imageLine.split(" ")[1];

    QString levImLine = lvlList[1];
    QString totalLevNumStr = levImLine.split(" ")[0];
    numOfLevels = totalLevNumStr.toInt();

    victoryImage.load(vicImStr);
    defeatImage.load(defImStr);
}



void Breakout::setLevel()
{
    QString levImLine = lvlList[1];
    QString backgroundStr = levImLine.split(" ")[level];

    backGround.load(backgroundStr);
    int trueArray[60];

    for(int i=0; i<10; i++)
    {
         QString levLine = lvlList[(level-1)*11+3+i];

         for (int a=0; a<6;a++)
         {
              QString rowsStr = levLine.split(" ")[a];
              trueArray[a+i*6] = rowsStr.toInt();
         }
    }

    qDebug()<< "true array values:"<< endl;
    for(int i = 0; i<60; i++)
    {
        qDebug() << trueArray[i];
    }

    int k = 0;
    for (int i=0; i<10; i++)
    {
      for (int j=0; j<6; j++)
      {
          bricks[k] = new Block(j*40+30, i*12+50);

          if(trueArray[k] == 0)
          {
              bricks[k]->setDestroyed(TRUE);
          }
          else bricks[k]->setDestroyed(FALSE);

          k++;
      }
    }
}

// Graphics control using paintEvent.
void Breakout::paintEvent(QPaintEvent * event)
{
   // instance of Qpainter
  QPainter painter(this);

  painter.drawImage(0,0,backGround);

  QPoint point = QPoint(0,10);
  QPoint point2 = QPoint(240,10);

  painter.drawText( point, "Level: "+QString::number(level-1 + count));
  painter.drawText( point2, "Score: " + QString::number(score));

  if (gameOver) {
    painter.drawImage(-45,0,defeatImage);
    painter.drawText( point2, "Score: " + QString::number(score));
    score=0;
    level=1;
    count=1;
    setLevel();
  }
  else if(gameWon) {
      painter.drawImage(-45,20,victoryImage);
      painter.drawText( point2, "Score: " + QString::number(score));
      score=0;
      level=1;
      count=1;
      setLevel();
  }
  else {
    painter.drawImage(ball->getRect(),ball->getImage());
    painter.drawImage(paddle->getRect(),paddle->getImage());

    for (int i=0; i<60; i++) {
        if (!bricks[i]->isDestroyed())
          painter.drawImage(bricks[i]->getRect(),bricks[i]->getImage());
    }
  }
}

// Initiation of repaint event based on the timer and collision status
void Breakout::timerEvent(QTimerEvent *event)
{
  ball->autoMove();
  checkCollision();
  repaint();
}

// Key press event handler
void Breakout::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
       {  
         int x = paddle->getRect().x();
        for (int i=1; i<=5; i++)
          paddle->moveLeft(x--);
        break;
       }
    case Qt::Key_Right:
        { 
          int x = paddle->getRect().x();
          for (int i=1; i<=5; i++)
            paddle->moveRight(x++);
        }
        break;
    case Qt::Key_P:
        { 
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

// Start of the game flag set up
void Breakout::startGame()
{ 
  if (!gameStarted) {
    ball->resetBallState();
    paddle->resetPaddleState();

    for (int i=0; i<60; i++) {
      //bricks[i]->setDestroyed(FALSE);
    }
    gameOver = FALSE; 
    gameWon = FALSE; 
    gameStarted = TRUE;
    timerId = startTimer(10);  
  }
}

//// Pause in the game flag set up
void Breakout::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId); 
   }
}

//  Game Over flag set up
void Breakout::stopGame()
{
  killTimer(timerId);    
  gameOver = TRUE;      
  gameStarted = FALSE;
}

// Game won flag set up
void Breakout::victory()
{
  killTimer(timerId);
  gameWon = TRUE;  
  gameStarted = FALSE;
}

// Next  level flag set up
void Breakout::nextLevel()
{
    level++;
    killTimer(timerId);
    gameWon = FALSE;
    gameStarted = FALSE;
}

// Check for collision with walls, blocks, or paddle
// Check if the ball breaks the bottom plane for game over
void Breakout::checkCollision()
{

  if (ball->getRect().bottom() > 400)
    stopGame(); 

  for (int i=0, j=0; i<60; i++) {
    if (bricks[i]->isDestroyed()) {
      j++;
    }
    if (j==60)
      checkLevel();
  }

  if ((ball->getRect()).intersects(paddle->getRect())) {

    int paddleLPos = paddle->getRect().left();  
    int ballLPos = ball->getRect().left();   

    int first = paddleLPos + 8;
    int second = paddleLPos + 16;
    int third = paddleLPos + 24;
    int fourth = paddleLPos + 32;

    if (ballLPos < first) {
      ball->setXDir(-1);
      ball->setYDir(-1);
    }

    if (ballLPos >= first && ballLPos < second) {
      ball->setXDir(-1);
      ball->setYDir(-1*ball->getYDir());
    }

    if (ballLPos >= second && ballLPos < third) {
       ball->setXDir(0);
       ball->setYDir(-1);
    }

    if (ballLPos >= third && ballLPos < fourth) {
       ball->setXDir(1);
       ball->setYDir(-1*ball->getYDir());
    }

    if (ballLPos > fourth) {
      ball->setXDir(1);
      ball->setYDir(-1);
    }
  }


  for (int i=0; i<60; i++) {
    if ((ball->getRect()).intersects(bricks[i]->getRect())) {
      int ballLeft = ball->getRect().left();  
      int ballHeight = ball->getRect().height(); 
      int ballWidth = ball->getRect().width();
      int ballTop = ball->getRect().top();  

      QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
      QPoint pointLeft(ballLeft - 1, ballTop);  
      QPoint pointTop(ballLeft, ballTop -1);
      QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);  

      if (!bricks[i]->isDestroyed()) {
        if(bricks[i]->getRect().contains(pointRight)) {
           ball->setXDir(-1);
        } 

        else if(bricks[i]->getRect().contains(pointLeft)) {
           ball->setXDir(1);
        } 

        if(bricks[i]->getRect().contains(pointTop)) {
           ball->setYDir(1);
        } 

        else if(bricks[i]->getRect().contains(pointBottom)) {
           ball->setYDir(-1);
        } 

        bricks[i]->setDestroyed(TRUE);
        score++;
      }
    }
  }

}

