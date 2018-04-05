#include <iostream>
#include <vector>
#include <string>


int main() {
	char arr[]={'a','b','c'};
	std::vector<std::string> vec;
	//creating a string from single character
	// you can't do append on an an unallocated memory like ""+arr[i
	//vec.push_back(""+arr[i])
	// this will throw error
	for(int i=0;i<3;i++)
		vec.push_back(std::string(1,arr[i]));
	for(int i=0;i<3;i++)
		std::cout<<vec[i]<<std::endl;

	std::string s = "";
	//appending to a string works 
	for(int i=0;i<3;i++)
		s += arr[i];
	std::cout<<s<<std::endl;
	return 0;
}