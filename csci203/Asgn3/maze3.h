#include <vector>

using namespace std;

class maze{
public:
	maze(int, int);
   	~maze();
   	void Generate(); // Generate the maze
   	void show(); // Display the maze
private:
	void createEdges();
	void shuffleVector();
	void kruskal();
	void convertToPaintedPoint();

	int width;
	int height;
	std::vector<pair<int, int> > all_edges;
	std::vector<pair<int, int> > mst_edges;
	std::vector<pair<int, int> > points;

	inline int Pos2Idx(int row, int column) {
		return row * width + column;
	}

	inline std::pair<int, int> Idx2Pos(int idx) {
		int row = idx / width;
		int column = idx % width;
		return std::pair<int, int>(row, column);
	}
};