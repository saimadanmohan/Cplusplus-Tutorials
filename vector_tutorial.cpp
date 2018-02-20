#include <iostream>
#include <vector>



int main() {
	int a[] = {1,2,4};
	// initialization with array
	std::vector<int> arr(a,a+sizeof(a)/sizeof(a[0])) ; 
	//reference variable
	std::vector<int> &b = arr;
	std::vector<int> c;
	std::cout<<arr.size()<<std::endl;
	b = c;
	b.push_back(5);
	std::cout<<arr.size()<<std::endl;
	//static initialization
	std::vector<std::string> arr2({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
	std::cout<<arr2.size()<<std::endl;
	//2d vector declaration
	vector<vector<int>> adj_list(edges.size()-1,vector<int>(0,0));
	//1d vector declaration
	vector<int> visited(edges.size()-1,0);

	//vector copy from b to a
	vector<int> a;
	vector<int> b;
	a.insert(a.end(), b.begin(), b.end());

	//vector erase 
    int start = 0;//something
    int end = 2;//something

	intervals.erase(intervals.begin()+start,intervals.begin()+end);
	return 0;
}