/*
Program by Davide Forgione
Assignment for Programming Methedology II, Concordia University
Winter 2023

Learning concepts include:
- Object Oriented Programming
- Polymorphism
- Dynamic Memory Managment
- File Handling
- Exception Handling

This is a program for the two player board game Othello.
When started, the user will be asked to either load an existing game or start a new one. 
The game follows by prompting players to take turns placing pieces on the "board". 
Players must enter the y coordinate, press enter, enter x coordinate, press enter again, 
before passing the computer to the next player.
A playable position is one where the player outflanks one or more pieces of the opposite colour.
A piece or row of pieces is outflanked when it has pieces of the opposite colour at its ends.
A piece or row of pieces can be outflanked in any direction (including diagonal).
Players will have the option to save the game or concede the game at the beginning of every turn.
If a player has no playable positions, they will have an option to forfeit their turn.
Game continues until both players no longer have playable positions, after which, the 
player with the most pieces on the board will be declared the winner.
*/

#include "position.h"
#include <iostream>
using namespace std;

position::position(char x){
	if (x=='.'){
			piece=EMPTY;
		}
		else if (x=='B'){
			piece=BLACK;
		}
		else if (x=='W'){
			piece=WHITE;
		}
		else {
			cout<<"error invalid piece in constructor";
		}
}

position::position(){
	piece=EMPTY;
}

void position::setPiece(char x){
	if (x=='.'){
		piece=EMPTY;
	}
	else if (x=='B'){
		piece=BLACK;
	}
	else if (x=='W'){
		piece=WHITE;
	}
	else {
		std::cout<<"error invalid piece";
	}
}
char position::getPiece(){return piece;}
position::~position(){}
