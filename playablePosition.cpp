#include <iostream>
#include "playablePosition.h"
using namespace std;

bool playablePosition::canPlay(){
	return true;
}

playablePosition::playablePosition(char x){
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
			cout<<"error invalid piece in constructor";
		}
}

playablePosition::playablePosition(){setPiece('.');}

playablePosition::~playablePosition(){}