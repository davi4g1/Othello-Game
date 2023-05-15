
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
