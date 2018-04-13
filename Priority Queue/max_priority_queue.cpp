#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int,vector<int>,less<int> > max_pq;
	for(int  i = 0; i < 10; i++)
		max_pq.push(i);
	cout<<max_pq.top();
	return 0;
}