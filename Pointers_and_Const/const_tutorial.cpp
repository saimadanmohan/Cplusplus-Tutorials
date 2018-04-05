//https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
#include<iostream>
using namespace std;

void constFunction(const int num){
	//invalid operation
	//num *= num;
}
void nonConstFunction(int num){
	num *=num;
	cout<<"nonConstFunction "<<num<<endl;
}
void nonConstFunctionByReference(int &num){
	num *=num;
	cout<<"nonConstFunctionByReference "<<num<<endl;	
}

int main(){
	const int x = 4;
	int y = 4;

	/* 	
		invalid case
		constFunction(x); 
		constFunction(y);
	*/

	//passing const value to non const parameter
	// via pass by value
	// and if we are modifying this parameter
	// it wont throw any error
	// as we are modifying a cloned copy
	// but not an original copy
	nonConstFunction(x);
	nonConstFunction(y);



	/*
		this function call is not legal
		as we are passing this const value by reference
		and we are modifying the the value
		in the function which is invalid
		nonConstFunctionByReference(x);
	*/
	nonConstFunctionByReference(y);
	return 0;
}