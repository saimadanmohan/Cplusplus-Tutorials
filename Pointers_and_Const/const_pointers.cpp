#include<iostream>
using namespace std;
int main(){
	int i = 4,j=5;

	//here const is applied to datatype
	//so data cannot be changed
	// ptr can be pointed to some other address location
	// this is perfectly valid
	const int * ptr = &i;
	ptr =&j;

	// in this case const is applied to  the pointer
	// pointer cannot be mapped to some other address
	// but the value at the address held by the pointer
	// can be changed 
	
	
	int * const  ptr1 = &j;
	*ptr1 = 6;


	// in this case pointer cannot be pointer to some other
	// address location and also the value at the address
	// cannot be changed
	const int * const ptr3 = &j;

	//in this case ptr can be pointed to different address
	//location and value also can be modified
	int *ptr4 = &j;
	ptr4 = &i;
	*ptr4 = 10;


	return 0;
}