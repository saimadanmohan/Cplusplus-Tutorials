//you should not pass function's local value as return variable by reference
#include <iostream>
using namespace std;

int& squareRefReturnVal(int number){
	int localVariable = number;
	return localVariable;
}

int* squarePtrReturnVal(int number){
	int localVariable = number;
	return &localVariable;
}

int main(){
	int number = 8;
	int & squareRefVal = squareRefReturnVal(number);
	cout<<"squareRefVal "<<squareRefVal<<endl;
	int * squarePtrVal = squarePtrReturnVal(number);
	cout<<"squarePtrVal "<<*squarePtrVal<<endl;
	return 0;
}
//
//This program has a serious logical error, as local variable 
//of function is passed back as return value by reference. 
//Local variable has local scope within the function, and its
// value is destroyed after the function exits. The GCC compiler
// is kind enough to issue a warning (but not error).