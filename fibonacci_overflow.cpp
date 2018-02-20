#include <iostream>
using namespace std;

int main() {
	int f0 = 0;
	int f1 = 1;
	int fn = f1+f0;
	while(1 ){
		f0 = f1;
		f1 = fn;

		fn = f1+f0;
		cout<<fn<<endl;
		if(fn< 0 )
		  break;
	}
	cout<<f1<<endl;
	return 0;
}