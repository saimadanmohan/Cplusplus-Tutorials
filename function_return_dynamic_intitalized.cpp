#include <iostream>
using namespace std;

int * squarePtr(int num){
	int *result = new int(num * num);
	return result;
}
int & squareRef(int num){
	int *result = new int(num * num);
	return *result;
}
int main(){
	int x = 5;
	int *squarePtrVal = squarePtr(5);
	cout<<*squarePtrVal<<endl;
	int &squareRefVal = squareRef(5);
	cout<<squareRefVal<<endl;
	return 0;
}