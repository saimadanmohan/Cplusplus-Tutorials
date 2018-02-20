#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
static int comp(pair<int,int> &a,pair<int,int> &b){
	return a.first < b.first;
}

//in this case 
// if (1,0) is (1,4) is compared with 1 <= 1
static int comp1(pair<int,int> &a,pair<int,int> &b){
	return a.first <= b.first;
}

int main()
{
	//vector<pair<int,int> > vec = {{1,1},{2,3},{1,4}};
	std::vector<std::pair<int, int> > vec1 = { {1, 0}, {2,0}, {3,1} ,{1,4}};
	//sort(vec1.begin(),vec1.end(),comp);
	sort(vec1.begin(),vec1.end(),comp1);

	for(auto v: vec1){
		cout<<v.first<<" "<<v.second<<endl;
	}
	return 0;
}