#include <iostream>
#include <map>
using namespace std;
 
int main() {
	map<string,int> rmap;
	rmap["a"] = 1;
	rmap["bad"] = 3;
	rmap["d"] = 0;
	rmap["b"] = 2;
	rmap["$"] = 3;
 
	for(auto it: rmap){
		cout<<it.first<<" "<<it.second<<" ";
	}
	cout<<endl;
	return 0;
	return 0;
}