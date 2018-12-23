#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int minimumVerticalSlice(vector<vector<int> > matrix) {
	auto clone(matrix);
	for(int i = 1; i < matrix.size(); i++) {
		for(int j = 0; i < matrix[0].size(); j++) {
			clone[i][j] += min 
		}		
	}
	return 0;
}

int main() {
	srand(time(0));
	vector<vector<int> > matrix(100, vector<int>(100, 0));
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; i < matrix[0].size(); j++) {
			matrix[i][j] = rand() % 100;			
		}		
	}
	minimumVerticalSlice(matrix);
	return 0;
}