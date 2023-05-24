/*
Program by Davide Forgione
Assignment for Programming Methedology II 
Winter 2023

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

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(const player p1, const player p2): a{p1,p2,1}{


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


	int boardType{0};
	string temp;

	while (true) {
			cin>>temp;

									        try {
									           unsigned int x = std::stoi(temp);
									           if (x>=3 || x<=0) {

						   throw std::out_of_range("Error: option must be between 1 and 2");
									            }
									            break;
									        }
									         catch (const std::invalid_argument& e) {
				std::cout << "Error: Invalid input. Please enter a number." << std::endl;
							        }
									        catch (const std::out_of_range& e) {
									            cout << e.what() << std::endl;
									        }
									    }
				      boardType=stoi(temp);


		if (boardType < 1 || boardType > 2){
		cerr<<"Invalid board type, try again "<<endl;}


	a.setBoardType(boardType);

	a.play();
}

