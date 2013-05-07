// ////////////////////////////////////////////////////////
//
// Assignment: Final Project - Breakout game
// File:  main.cpp
//
// Authors: Denis Pelevin/Kevin DiMaria
// 
// Base code that we used was found at 
// http://www.zetcode.com/gui/qt4/breakoutgame/
//
// Submited on 05/04/2013
//
// ///////////////////////////////////////////////////////

#include "breakout.h"
#include <QDesktopWidget>
#include <QApplication>

// Sets up winodw size and center coordinates
void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 300;
  int HEIGHT = 400;
  

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

// main function
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  // create window
  Breakout window;
  
  // show breakout window
  window.setWindowTitle("Breakout");
  center(window);
  window.show();

// enter the event loop
  return app.exec();
}
