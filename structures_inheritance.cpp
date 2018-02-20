#include <iostream>
using namespace std;

struct A{
	int add(int a,int b){
		return a+b;
	}
};

struct B:A{
	int add(int a,int  b){
		return a+b;
	}
};
int main() {
	A a;
	B b;
	cout<<a.add(2,3)<<endl;
	cout<<b.add(4,3)<<endl;
	return 0;
}