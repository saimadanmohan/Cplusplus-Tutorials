#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> vec{1,2,3,4,4,4,5,5};
	int index = (int) (lower_bound(vec.begin(), vec.end(), 4) - vec.begin());
	int index2 = (int) (upper_bound(vec.begin(), vec.end(), 4) - vec.begin());
	cout<<index<<endl;
	cout<<index2<<endl;
	return 0;
}