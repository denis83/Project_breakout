####################################### WELCOME ####################################################

Thank you for trying out our Breakout game.
It was developed by Kevin DiMaria and Denis Pelevin.

####################################### CREDITS ####################################################

Base code that included inputs/outputs and basic game logic should be credited to creators of

	http://www.zetcode.com/gui/qt4/breakoutgame/

######################################## IMPORTANT ##################################################
This particular project was developed using Qt IDE, so if you dont have it installed on your computer it will not compile.

However, Qt Creator is free to download and if you don't have it yet it is a very powerful software development tool and we highly recomend it. To install QtCreator just run

	sudo apt-get install qtcreator


If you already have Qt installed just run "qmake" and "make" commands to compile.

######################################## Game play #####################################################

Game itself is not very complicated. 
	spacebar 			- start the game on each level
	left, right arrow keys 		- control paddle
	p				- pause/resume game
	esc				- quit game

There are 3 levels to start you off and you only get 1 life.

######################################## Personalized levels ###########################################

Within lvl.config file one may adjust images for backgrounds or block layouts for different levels.

line1: put image containing files for victory or defeat screen separated by a whitespace
line2: number of levels, background files for each level

Maps with zeros and ones represent layout of blocks for a particular level. 1 = block ON, 0 = block OFF


Thats about it!
Enjoy!!

	
