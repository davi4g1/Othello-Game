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
#include "position.h"
#include "player.h"
#include "Board.h"
#include "Game.h"
using namespace std;


int main(){

	int option;
	string a,b;
	string temp;

	cout<<"Welcome to Othello!\nChoose your option:\n1. Quit\n2. Load a Game\n3. Start a Game"<<endl;

	while (true) {
								  std::getline(std::cin, temp);


								        try {
								           unsigned int x = std::stoi(temp);
								           if (x>=4 || x<=0) {

					   throw std::out_of_range("Error: option must be between 1 and 3");
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
			      option=stoi(temp);

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
