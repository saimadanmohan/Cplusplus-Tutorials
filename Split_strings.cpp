#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
	string s = "a_long_long_long_time";	
	vector<string> string_set;
	int kmer_size = 5;
	for(int i=0;i<=s.size()-kmer_size;i++){
		string_set.push_back(s.substr(i,kmer_size));
	}
	int k_minus_one_mer_size = kmer_size - 1;
	for(int i=0;i<string_set.size();i++)
		cout<<string_set[i].substr(0,k_minus_one_mer_size)<<" "<<string_set[i].substr(1,k_minus_one_mer_size)<<endl;
		cout<<endl;
	return 0;
}