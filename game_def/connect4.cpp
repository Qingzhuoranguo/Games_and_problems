#include "../games.h"
#include <iostream>
#include <iterator>

// Private methods:
bool Connect4::isValidDecision ( int pos ) {
    for (auto v : ValidDecision) {
        if  (v == pos) {
            return true;
        }
    } 
    return false;
}

int Connect4::checkwin( int x, int y) {
    // virtical
    if (x>2)
		if (Board[x][y]==Board[x-1][y] && 
			Board[x][y]==Board[x-2][y] && 
			Board[x][y]==Board[x-3][y])
			
			return Board[x][y];
	// horizontal
	for (int c = 0; c < std::min(4,y+1); c++)
		if (y-c<4 && Board[x][0+c]==Board[x][1+c] && 
			Board[x][0+c]==Board[x][2+c] && 
			Board[x][0+c]==Board[x][3+c])

			return Board[x][y];
	// diagonal up right
	int r = x+3;
	int c = y-3;
	// std::cout << "x=" << x << "y=" << y << std::endl;
	for (uint8_t k = 0; k < 4; k++){
		if (r<6 && r-3>-1 && c>-1 && c+3<7){
			if (Board[r][c]==Board[r-1][c+1] &&
				Board[r][c]==Board[r-2][c+2] &&
				Board[r][c]==Board[r-3][c+3])

				return Board[x][y];
		}
		r--;
		c++;
	}

	// diagonal up left
	r = x+3;
	c = y+3;
	//std::cout << "x=" << +x << "y=" << +y << std::endl;
	// std::cout << "r=" << r << "c=" << c << std::endl;
	for (uint8_t k = 0; k < 4; k++){
		// std::cout << "diagonal up left" << std::endl;
		//std::cout << "r=" << r << "c=" << c << std::endl;
		if (r<6 && r-3>-1 && c<7 && c-3>-1){
			//std::cout << "satisfied" << std::endl;
			if (Board[r][c]==Board[r-1][c-1] &&
				Board[r][c]==Board[r-2][c-2] &&
				Board[r][c]==Board[r-3][c-3])

				return Board[x][y];
		}
		r--;
		c--;
	}
	return 0;
}


// Public method:
Connect4::Connect4 (): Game(), ProgressCount(0) {
	for (int j = 0; j < 7; j++){
        ValidDecision.push_back(j);
        for (int i = 0; i < 6; i ++) {
			Board[i][j] = 0;
		}
	}
}

/*
Returns:
win: player#
tie: 0
still playing: -1;
*/
int Connect4::getGameStatus( void *opt = nullptr ){
    if (Game::GameStatus == ON ) {
        return -1;
    }else if ( Game::GameStatus == TIE){
        return 0;
    }else if (Game::GameStatus == WIN) {
        return (ProgressCount-1)%2 + 1;
    }else {
		puts("== Connect4::getGameStatus: Error: Undefined game status.");
		return -3;
	}
}

int Connect4::MakeDecision ( void *target ) {
    if ( Game::GameStatus != ON ){
        return -1;
    }
    // Game still ON:
    int pos = *(int *)target - 1;
    if ( not isValidDecision( pos ) ) {
        return -2;
    }
    // find the last unoccuppied position
    for ( int i = 0; i < 6; i++ ){
        if ( Board[i][pos] == 0 ){
            Board[i][pos] = (ProgressCount%2) + 1;
            ProgressCount ++;

            int result = checkwin( i, pos );

            // if someone wins
            if (result > 0){
                ValidDecision.clear();
                Game::GameStatus = WIN;
                return 1;
            }
            // if no one wins
            if ( i == 5 ){ // check if it's the top entry
                ValidDecision.remove(i);
                if (ValidDecision.empty()){
                    Game::GameStatus = TIE;
                }
            }
            break;
        }
    }
    return 0;
}

int Connect4::TurnInfo () {
    std::cout << "Now is Player" << (ProgressCount%2) + 1 << "'s turn.\n";
	return (ProgressCount%2) + 1;
}

void Connect4::DisplayGame() {
    std::cout << "The current game board is: \n";
	for (int i = 5; i >-1; i --){
		std::cout<<"   +---+---+---+---+---+---+---+"<<std::endl;
		for (int j = 0; j < 7; j ++){
			if (j==0){
				std::cout << " " << char(97+i) << " |";
			}
			if (Board[i][j]==0){
				std::cout << "  ";
			}else if (Board[i][j]==1){
				std::cout << " X";
			}else{
				std::cout << " O";
			}
			std::cout <<" |";
		}
		std::cout << std::endl;
	}
	std::cout<<"   +---+---+---+---+---+---+---+"<<std::endl;
	std::cout<<"     1   2   3   4   5   6   7"<<std::endl <<std::endl;
}