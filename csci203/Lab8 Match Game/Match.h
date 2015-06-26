#define LOSE -1
#define WIN 1
#define DRAW 0
#define F false
#define T true

class match {
private:
	int take, numOfMatches;
	bool humanTurn;
	int node[11];
	bool edge[11][11];
public:
	match ();
	void startGame ();
	bool endGame ();
	int computerTurn ();
};

