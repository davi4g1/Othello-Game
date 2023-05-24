
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
