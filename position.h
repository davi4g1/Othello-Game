
#ifndef POSITION_H_
#define POSITION_H_

class position{

public:
	virtual bool canPlay()=0;
	static const char EMPTY = '.';
	static const char BLACK = 'B';
	static const char WHITE = 'W';
	virtual void setPiece(char x);
	virtual char getPiece();
	position(char);
	position();
	virtual ~position();



private:
	char piece;

};



#endif /* POSITION_H_ */
