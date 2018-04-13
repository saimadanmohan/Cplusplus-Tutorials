#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int> > min_pq;
	for(int  i = 0; i < 10; i++)
		min_pq.push(i);
	cout<<min_pq.top();
	return 0;
}