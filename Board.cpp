
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "Board.h"
#include "Game.h"

Board::Board(player p1,player p2,int start) : playerW(p1), playerB(p2)
{
    for(int i = 0; i < 8; i++){
    	for(int j=0;j<8;j++){

    		pBoard = new playablePosition;
    		board[i][j]=pBoard;

        	board[i][j]->setPiece(position::EMPTY);

setCurrentTurn(&p1);
}}}

Board::~Board() {

	for(int i = 0; i < 8; i++){
	    	for(int j=0;j<8;j++){
	   delete board[i][j];
	    	}}
/*
	playerW.~player();
	playerB.~player();
	currentTurn.~player();
*/
}

Board::Board(){
}

void Board::setP1(player &x){
        	x=playerW;
        }

void Board::setP2(player &x){
        	x=playerB;
        }

void Board::setBoardType(int x){

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board[3][3];
		board[3][3]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [3][4];
		board[3][4]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [4][3];
		board[4][3]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board [4][4];
		board[4][4]=qBoard;


	if (x==2){

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board[2][3];
		board[2][3]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board [2][2];
		board[2][2]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board [3][2];
		board[3][2]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [4][2];
		board[4][2]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board[5][3];
		board[5][3]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [5][2];
		board[5][2]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [2][4];
		board[2][4]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [2][5];
		board[2][5]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::BLACK);
		delete board [3][5];
		board[3][5]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board[4][5];
		board[4][5]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board [5][5];
		board[5][5]=qBoard;

		qBoard=new unplayablePosition;
		qBoard->setPiece(unplayablePosition::WHITE);
		delete board [5][4];
		board[5][4]=qBoard;

	}
}

void Board::draw() {


	int a{0};
cout<<"  0 1 2 3 4 5 6 7";
	 for(int i = 0; i <8; i++){
		 cout<<endl;
		 cout<<a++<<' ';
		 for(int j=0; j<8; j++){
	cout<<board[i][j]->getPiece()<<' ';
		 }
}
cout<<endl<<endl;;

}

void Board::takeTurn() {
        draw();

               	cout<<getCurrentTurn().getName()<<", please enter a";
            	if (getCurrentTurn().getName()==getP1().getName()){
            		cout<<" WHITE piece by choosing y then x coordinates from 0 to 7 ";
            	}
            	else {
            		cout<<" BLACK piece by choosing y then x coordinates from 0 to 7 "<<endl;
            	}
            	int a,b;
            	bool c{false};
            	string temp,temp2;

            	while(c==false){
            					while (true) {
            						cin>>temp>>temp2;

            								try {
            									unsigned int x = std::stoi(temp);
            									unsigned int y = std::stoi(temp2);
            									if (x<0 || x>7 || y<0 || y>7) {

            				throw std::out_of_range("Error: option must be between 0 and 7");

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
            								      a=stoi(temp);
            								      b=stoi(temp2);

            	if (board[a][b]->canPlay()==false){
            	      cout<<"Unplayable Position, try again: "<<endl;
            	      c=false;
            	} else {
            		delete board[a][b];
            		 qBoard=new unplayablePosition();
            		if (getCurrentTurn().getName()==getP1().getName()){
            		 qBoard->setPiece('W');
            		}
            		else {
            		qBoard->setPiece('B');
            	}
            		 board[a][b]=qBoard;
            		 doFlip(a,b);
            		 c=true;
            }
            	}
}


bool Board::canMakeMove(){
if (getCurrentTurn().getName()==getP1().getName()){
		     checkBoard('W');
		                   }
		else {
		     checkBoard('B');
		                   }
		for(int i = 0; i < 8; i++){
		for(int j=0; j<8; j++){
			if (board[i][j]->canPlay()==true){
				return true;
				}

		}}
		return false;
}

void Board::checkWin(){

	if (totalW>totalB){
		cout<<"White Won!"<<endl;
	}
	else if(totalW<totalB) {
		cout<<"Black Won!"<<endl;
	}
	else {
		cout<<"tie";
	}
}


bool Board::checkRow(char c, int i, int j, int i_dir, int j_dir){


	bool cond=false;
	if ((i+i_dir < 0) || (i+i_dir >= 8) || (j+j_dir < 0) || (j+j_dir >= 8)){return false;}
	if (board[i+i_dir][j+j_dir]->getPiece()!=position::EMPTY){
		   if (c != board[i+=i_dir][j+=j_dir]->getPiece()){
		    	while (i<=7||i>0||j<=7||j>0){
		    		if ((i+i_dir < 0) || (i+i_dir >= 8) || (j+j_dir < 0) || (j+j_dir >= 8)){return false;}

		    		if (c !=board[i+=i_dir][j+=j_dir]->getPiece()){
		    			cond=false;
		    		}
		    		else {cond=true;
		    		break;
		    	}
		    }}
		    if (cond){
		    	return true;
		    }
		    else {
		    return false;
	}
	}}

void Board::checkBoard(char c){

	totalW=0;
	totalB=0;

	bool cond{false};
	for(int i = 0; i < 8; i++){
		for(int j=0; j<8; j++){

			if (board[i][j]->getPiece() == position::WHITE){
			totalW++;
				}
			else if (board[i][j]->getPiece() == position::BLACK){
				totalB++;
					}

	if(board[i][j]->getPiece() != position::EMPTY)
	   {cond=false;}
	else if(checkRow(c,i,j,1,0)){
		cond= true;}
	else if(checkRow(c,i,j,-1,0)){
		cond= true;}
	else if(checkRow(c,i,j,0,1)){
		cond= true;}
	else if(checkRow(c,i,j,0,-1)){
		cond= true;}
	else if(checkRow(c,i,j,1,1)){
		cond= true;}
	else if(checkRow(c,i,j,1,-1)){
		cond= true;}
	else if(checkRow(c,i,j,-1,1)){
		cond= true;}
	else if(checkRow(c,i,j,-1,-1)){
		cond= true;}
	else {cond= false;};


	if (cond==false){
		qBoard=new unplayablePosition;
		qBoard->setPiece(board[i][j]->getPiece());
		delete board[i][j];
		board[i][j]=qBoard;
	}
	else{
		pBoard=new playablePosition;
		pBoard->setPiece(board[i][j]->getPiece());
		delete board[i][j];
		board[i][j]=pBoard;
	}

	    }
	}}

void Board::flip(int i, int j, int i_dir, int j_dir){

	int a=i;
	int b=j;
		while (board[a][b]->getPiece()!=board[i+i_dir][j+j_dir]->getPiece()){
			if ((i+i_dir < 0) || (i+i_dir >= 8) || (j+j_dir < 0) || (j+j_dir >= 8)){break;}
			  if (board[i+i_dir][j+j_dir]->getPiece()==position::WHITE){
			    	board[i+=i_dir][j+=j_dir]->setPiece(position::BLACK);
			   }
			    else {
			    	board[i+=i_dir][j+=j_dir]->setPiece(position::WHITE);
}}}


void Board::doFlip(int i, int j){

	char c;
	if (getCurrentTurn().getName()==getP1().getName()){
			c=position::WHITE;
		}
		else {
			c=position::BLACK;
		}

bool cond;

	if(board[i][j]->getPiece() != position::EMPTY)
	{
		 if(checkRow(c,i,j,1,0)){
			flip(i,j,1,0);}
		 if(checkRow(c,i,j,-1,0)){
			flip(i,j,-1,0);}
		 if(checkRow(c,i,j,0,1)){
			flip(i,j,0,1);}
		 if(checkRow(c,i,j,0,-1)){
			flip(i,j,0,-1);}
		 if(checkRow(c,i,j,1,1)){
			flip(i,j,1,1);}
		 if(checkRow(c,i,j,1,-1)){
			flip(i,j,1,-1);}
		 if(checkRow(c,i,j,-1,1)){
			flip(i,j,-1,1);}
		 if(checkRow(c,i,j,-1,-1)){
			flip(i,j,-1,-1);}

		}
}

void Board::play(){
	int option;

	if(!canMakeMove()){
		if(getCurrentTurn().getName()==playerW.getName()){
						setCurrentTurn(&playerB);
	}
	else {
						setCurrentTurn(&playerW);
	}}

	while (canMakeMove()){

draw();
		cout<<getCurrentTurn().getName()<<":\nThere are playable moves. Choose Option:"<<endl;
				cout<<"1. Make Move\n2. Save Game\n3. Concede the Game"<<endl;

				string temp;
				while (true) {
					cin>>temp;

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

				if (option==1){
			takeTurn();
					if(getCurrentTurn().getName()==playerW.getName()){
						setCurrentTurn(&playerB);
					}
					else {
						setCurrentTurn(&playerW);
					}
				}
				else if(option==2){
					save();

				}
				else if(option==3){
					if(getCurrentTurn().getName()==playerW.getName()){
						draw();
						cout<<"Black Won!"<<endl;
						for(int i = 0; i < 8; i++){//////////////// deallocate before exiting
							    	for(int j=0;j<8;j++){
							   delete board[i][j];
							    	}}
						exit(EXIT_SUCCESS);
						}
					else{
						draw();
						cout<<"White Won!"<<endl;
						for(int i = 0; i < 8; i++){
							    	for(int j=0;j<8;j++){
							   delete board[i][j];
							    	}}
						exit(EXIT_SUCCESS);

	}}
		while(!canMakeMove()){

				draw();
				cout<<getCurrentTurn().getName()<<": No playable moves. Choose Option:"<<endl;
				cout<<"1. Forfeit Turn\n2. Save Game\n3. Concede the Game"<<endl;

				string temp;
								while (true) {
									cin>>temp;

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

				if (option==1){
					if(getCurrentTurn().getName()==playerW.getName()){
						setCurrentTurn(&playerB);
					if (!canMakeMove()){
						break;
							}
							}
					else {
						setCurrentTurn(&playerW);
					if (!canMakeMove()){
						break;
								}
					}
				}
					else if(option==2){
							save();
						}
					else if(option==3){
						if(getCurrentTurn().getName()==playerW.getName()){
						draw();
						cout<<"Black Won!"<<endl;
				for(int i = 0; i < 8; i++){////////////////////// deallocate before exiting
				    	for(int j=0;j<8;j++){
				    	delete board[i][j];
					    	}}

								exit(EXIT_SUCCESS);}
							else{
								draw();
								cout<<"White Won!"<<endl;
								for(int i = 0; i < 8; i++){
									    	for(int j=0;j<8;j++){
									   delete board[i][j];
									    	}}

								exit(EXIT_SUCCESS);
								}
					}}}

	draw();
	checkBoard('W');
	checkWin();

	for(int i = 0; i < 8; i++){
		    	for(int j=0;j<8;j++){
		   delete board[i][j];
		    	}}
	exit(EXIT_SUCCESS);
}

Board::Board(string save_file){

	istringstream saved(save_file);

	string player1,player2,currentPlayer,savedBoard;
	player one,two;

	getline(saved,player1);
	getline(saved,player2);
	getline(saved,currentPlayer);
	getline(saved,savedBoard);

	playerW.setName(player1);
	playerB.setName(player2);

	if (currentPlayer==playerW.getName()){
		setCurrentTurn(&playerW);
	}
	else if (currentPlayer==playerB.getName()){
		setCurrentTurn(&playerB);
	}
	else{
		cerr<<"player turn error";
	}

	for(int i = 0; i <= 63; i++){
		if (savedBoard[i]=='.'){
			pBoard=new playablePosition;
			pBoard->setPiece(position::EMPTY);
			board[i/8][i%8]=pBoard;
		}
		else if(savedBoard[i]=='B'){
			qBoard=new unplayablePosition;
			qBoard->setPiece(position::BLACK);
			board[i/8][i%8]=qBoard;
		}
		else if(savedBoard[i]=='W'){
			qBoard=new unplayablePosition;
			qBoard->setPiece(position::WHITE);
			board[i/8][i%8]=qBoard;
		}
}
}

void Board::save(){
	string fileN;
	cout<<"What do you want to name the file?"<<endl;
	cin>>fileN;
	ofstream saveBoard;

	saveBoard.open(fileN);

	if(saveBoard){

		saveBoard<<playerW.getName()<<endl;
		saveBoard<<playerB.getName()<<endl;
		saveBoard<<currentTurn.getName()<<endl;

			for(int i = 0; i <8; i++){
				 for(int j=0; j<8; j++){
			saveBoard<<board[i][j]->getPiece();
				 }
			 }}
	else{
		cout<<"file error";
	}
	saveBoard.close();

}

Board Board::load(){

	cout<<"Enter the name of the file you would like to load: "<<endl;
	string fileN;
	string x,player1,player2,currentPlayer,savedBoard;
	cin>>fileN;

	ifstream loadBoard{fileN};

	if (!loadBoard){
		cerr<<"File could not be opened please reload program"<<endl;
		exit(EXIT_FAILURE);
	}


	else{
		getline(loadBoard,player1);
		getline(loadBoard,player2);
		getline(loadBoard,currentPlayer);
		getline(loadBoard,savedBoard);

		}





	x=player1+"\n"+player2+"\n"+currentPlayer+"\n"+savedBoard+"\n";


	return Board{x};

	}
