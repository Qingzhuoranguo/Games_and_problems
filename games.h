#include <iostream>
#include <list>

class Game {
protected:
	enum Status { ON = 0, WIN, TIE };
	Status GameStatus;
public:
	Game ();
	inline uint32_t getKey () { return SearchKey; }

	virtual int getGameStatus ( void *opt = nullptr ) { return GameStatus; }
	virtual int MakeDecision ( void *target ) = 0;
	virtual void DisplayGame() = 0;
	virtual int TurnInfo () = 0;
	virtual void Settle ();
private:
	uint64_t SearchKey;
	uint64_t searchKeyGen();
};


class Connect4: public Game {
private:
	int Board [6][7];
public:
	Connect4 ();
	int MakeDecision ( void *target );
	int getGameStatus( void *opt );
	void DisplayGame();
	int TurnInfo ();
private:
	bool isValidDecision ( int pos );
	int checkwin ( int x, int y );
	
	// total placement
	uint8_t ProgressCount;

	// valid decisont set 
	std::list<int> ValidDecision;
};

