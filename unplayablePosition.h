#include <iostream>
#include "position.h"

#ifndef UNPLAYABLEPOSITION_H_
#define UNPLAYABLEPOSITION_H_

class unplayablePosition : public position{

public:
	bool canPlay() override;
	static const char UNPLAYABLE = '*';

	unplayablePosition(char x);
	unplayablePosition();
	~unplayablePosition() override;

private:

};



#endif /* UNPLAYABLEPOSITION_H_ */
