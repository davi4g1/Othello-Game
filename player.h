
#include <iostream>

#ifndef PLAYER_H_
#define PLAYER_H_

class player{

    public:
        player(std::string);
        player();

        void setName(std::string x){
        	name=x;
        }

        std::string getName() {
            return name;
        }

    private:
        std::string name;
};



#endif /* PLAYER_H_ */

