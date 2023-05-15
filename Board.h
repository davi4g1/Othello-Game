
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
