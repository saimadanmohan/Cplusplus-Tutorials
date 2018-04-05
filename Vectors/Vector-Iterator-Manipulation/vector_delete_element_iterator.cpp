#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[] = {1,2,3,4,5};
	vector<int> vec(a,a+sizeof(a)/sizeof(a[0]));
	bool to_remove = true;
	for(vector<int>::iterator it = vec.begin();it!=vec.end();it++){
		if(to_remove){
			vec.erase(vec.begin(),vec.end()-1);
			to_remove = !to_remove;
		}
		cout<<*it<<endl;
	}
	return 0;
}