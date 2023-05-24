
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

