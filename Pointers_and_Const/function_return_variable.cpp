//https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html
#include<iostream>
using namespace std;
int & squareRef(int & num){
	num *= num;
	return num;
}

int* squarePtr(int *num){
	*num *= *num;
	return num;
}

int main(){
	
	//here if you notice all the variables are pointing to the same memory address
	int number = 8;
	int & squareRefVal = squareRef(number);
	cout<<"squareRefVal "<<squareRefVal<<endl;
	int * squarePtrVal = squarePtr(&number);
	cout<<"squarePtrVal "<<*squarePtrVal<<endl;

	cout<<"squareRefVal "<<squareRefVal<<endl;

	cout<<"actual number "<<number<<endl;

	return 0;
}