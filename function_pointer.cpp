#include <iostream>
using namespace std;
int add(int a,int b){
	return a+b;
}

//(a+b)*c
int solve(int a,int b,int c,int (*operation)(int,int)){
	return a*((*operation)(b,c));
}

int main(){
	cout<<solve(2,3,4,add);
	return 0;
}