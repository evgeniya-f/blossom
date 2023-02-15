#include "blossom.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h> 

using namespace std;

int main() {

	vector<vector<int>> graph;
	ifstream infile("graph.txt");
	string line;
	while (getline(infile, line)) {
		vector<int> vertex;
		istringstream iss(line);
		int adjacent_vertex;
		while (iss >> adjacent_vertex) {
			vertex.push_back(adjacent_vertex);
		}
		graph.push_back(vertex);
	}

	vector<int> matching;
	clock_t start = clock();
	get_match(graph, matching);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	print_match(matching);

	return 0;

}