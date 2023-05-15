#include <iostream>
#include "unplayablePosition.h"

bool unplayablePosition::canPlay(){
return false;
}

unplayablePosition::unplayablePosition(char x){
	if (x=='.'){
			setPiece('.');
		}
		else if (x=='B'){
			setPiece('B');
		}
		else if (x=='W'){
			setPiece('W');
		}
		else {
			std::cout<<"error invalid piece in constructor";
		}
}

unplayablePosition::unplayablePosition(){setPiece('.');}

unplayablePosition::~unplayablePosition(){}
