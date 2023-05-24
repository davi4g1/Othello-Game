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

#include "player.h"
#include "position.h"
#include "playablePosition.h"
#include "unplayablePosition.h"


#ifndef BOARD_H_
#define BOARD_H_

 class Board {
    public:
        Board(player,player,int);
        virtual ~Board();

        Board();

        player getCurrentTurn() {
        return currentTurn; }

        void setP1(player&);

        void setP2(player&);

        player getP1(){
        	return playerW;
        }

        player getP2(){
               	return playerB;
               }

        void setBoardType(int);

        void setCurrentTurn(player* x) {
        currentTurn = *x;}

        void draw();
        void takeTurn();
        void checkBoard(char);
        bool checkRow(char,int,int,int,int);
        void flip(int,int,int,int);
        void doFlip(int,int);
        void play();

        bool canMakeMove();
        void checkWin();

        Board(std::string);
        static Board load();

    private:
        player playerW;
        player playerB;
        player currentTurn;

        position* board[8][8];
        playablePosition* pBoard;
        unplayablePosition* qBoard;


        int totalW{0};
        int totalB{0};

        void save();

};



#endif /* BOARD_H_ */
