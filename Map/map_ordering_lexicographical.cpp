#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
 
int main(void) {
	map<char,int> rmap{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
	rmap['a'] = 1;
	rmap['d'] = 0;
	rmap['b'] = 2;
	rmap['$'] = 3;
	for(auto it: rmap){
		cout<<it.first<<" "<<it.second<<" ";
	}
	cout<<endl;
	return 0;
}
 