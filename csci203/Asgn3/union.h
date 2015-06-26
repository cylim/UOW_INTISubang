#include <vector>

class Union{
	std::vector<int> _sets;
	int _number_of_sets;

public:
	Union() {
		_number_of_sets = 0;
	}

	void reset(int number_of_sets) {
		_sets.clear();
		_sets.resize(number_of_sets, -1);
		_number_of_sets = number_of_sets;
	}

	bool isUnion(int set_a, int set_b) {
		int root_a = find(set_a), root_b = find(set_b);
		if (root_a == root_b) return false;
		_sets[root_a] += _sets[root_b];
		_sets[root_b] = root_a;
		_number_of_sets--;
		return true;
	}

	int find(int element) {
		if (_sets[element] < 0) return element;
		return (_sets[element] = find(_sets[element]));
	}

	inline int getNumberOfSets() {
		return _number_of_sets;
	}
};