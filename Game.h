
#include "player.h"
#include "Board.h"

#include <fstream>

#ifndef GAME_H_
#define GAME_H_


class Game{

public:
	Game(player,player);
	Game();
	~Game();
	void start();

private:
	Board a;

};


#endif /* GAME_H_ */
