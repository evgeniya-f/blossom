#include "blossom.h"

using namespace std;

int main() {

	//список инцидентности
 /*   vector<int> copy[MAXN];
	copy[0] = vector<int>({ 1, 2, 3, 5 });
	copy[1] = vector<int>({ 0, 2, 3, 7, 9 });
	copy[2] = vector<int>({ 0, 1, 6 });
	copy[3] = vector<int>({ 0, 1, 7, 9 });
	copy[4] = vector<int>({ 6 });
	copy[5] = vector<int>({ 0 });
	copy[6] = vector<int>({ 2, 4 });
	copy[7] = vector<int>({ 1, 3, 8 });
	copy[8] = vector<int>({ 7 });
	copy[9] = vector<int>({ 1, 3 });
	*/

	vector<vector<int>> copy;
	copy.push_back(vector<int>({ 8, 9 }));
	copy.push_back(vector<int>({ 3, 4, 9 }));
	copy.push_back(vector<int>({ 7, 9 }));
	copy.push_back(vector<int>({ 1, 4, 8 }));
	copy.push_back(vector<int>({ 1, 3, 5, 9 }));
	copy.push_back(vector<int>({ 4, 9 }));
	copy.push_back(vector<int>({ 8 }));
	copy.push_back(vector<int>({ 2 }));
	copy.push_back(vector<int>({ 0, 3, 6 }));
	copy.push_back(vector<int>({ 0, 1, 2, 4, 5 }));
	std::vector<int> a;

	get_match(copy, a);

	print_match(a);

	return 0;

}