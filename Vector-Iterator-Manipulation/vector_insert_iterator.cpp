#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[] = {1,2,3,4,5};
	vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
	bool to_insert = true;
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++){
		if(to_insert){
            vec.insert(vec.begin(),6);//insertion at the begining
			to_insert = !to_insert;
		}
		cout<<*it<<endl;
	}
	return 0;
}