
#include <iostream>
#include "position.h"
#include "player.h"
#include "Board.h"
#include "Game.h"
using namespace std;


int main(){

	int option;
	string a,b;

	cout<<"Welcome to Othello!\nChoose your option:\n1. Quit\n2. Load a Game\n3. Start a Game"<<endl;
	cin>>option;

	while(option!=1 && option !=2 && option!=3){
		cout<<"try again";
		cin>>option;}
	if(option==1){
		cout<<"Thank you for playing! Bye!";
		return 0;
	}
	else if(option==2){
		Board::load().play();

	}
	else if(option==3){

	cout<<"Please enter Player 1 (White) name: ";
	cin>>a;
	cout<<"Please enter player 2 (Black) name: ";
	cin>>b;

	player x{a};
	player y{b};

	Game game{x,y};
	game.start();
	}

	else{
		cout<<"Invalid option, try again"<<endl;
	}


return 0;
}