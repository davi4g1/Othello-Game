
#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(const player p1, const player p2) : a{p1,p2,1}{



}

Game::Game(){
cout<<"w";
}

Game::~Game(){}

void Game::start(){

	cout<<"\nChoose starting board: \n\n 1. Standard Start:"<<endl;
	cout<<"  0 1 2 3 4 5 6 7\n";
	cout<<"0 . . . . . . . .\n";
	cout<<"1 . . . . . . . .\n";
	cout<<"2 . . . . . . . .\n";
	cout<<"3 . . . W B . . .\n";
	cout<<"4 . . . B W . . .\n";
	cout<<"5 . . . . . . . .\n";
	cout<<"6 . . . . . . . .\n";
	cout<<"7 . . . . . . . .\n"<<endl;
	cout<<"2. Four by Four Start:"<<endl;
	cout<<"  0 1 2 3 4 5 6 7\n";
	cout<<"0 . . . . . . . .\n";
	cout<<"1 . . . . . . . .\n";
	cout<<"2 . . W W B B . .\n";
	cout<<"3 . . W W B B . .\n";
	cout<<"4 . . B B W W . .\n";
	cout<<"5 . . B B W W . .\n";
	cout<<"6 . . . . . . . .\n";
	cout<<"7 . . . . . . . .\n";


	int boardType;
	while (boardType != 1 && boardType != 2){
	cin>>boardType;
	if (boardType < 1 || boardType > 2){
		cout<<"Invalid board type, try again "<<endl;}
		else {break;}

	}


	a.setBoardType(boardType);


	a.play();

}
