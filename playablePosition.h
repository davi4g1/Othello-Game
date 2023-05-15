
#include "position.h"

#ifndef PLAYABLEPOSITION_H_
#define PLAYABLEPOSITION_H_


class playablePosition : public position{

public:
	bool canPlay() override ;
	playablePosition(char x);
	playablePosition();
	~playablePosition() override;


private:

};


#endif /* PLAYABLEPOSITION_H_ */