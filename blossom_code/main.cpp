#include "blossom.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	vector<vector<int>> copy;
	ifstream infile("graph.txt");
	string line;
	while (getline(infile, line)) {
		vector<int> vertexes;
		std::istringstream iss(line);
		int a;
		while (iss >> a) {
			vertexes.push_back(a);
		}
		copy.push_back(vertexes);
	}

	std::vector<int> a;

	get_match(copy, a);

	print_match(a);

	return 0;

}
