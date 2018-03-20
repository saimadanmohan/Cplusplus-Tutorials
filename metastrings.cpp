#include <iostream>
using namespace std;

bool checkIfSingleSwap(string s1,string s2){
	int mismatch = 0;
	int prevMismatch = -1;
	int currMismatch = -1;
	if(s1.size() == s2.size()){
		for(int i = 0;i<s1.size();i++){
			if(s1[i] != s2[i]){
				mismatch++;
				if(mismatch  > 2)
					return false;
				prevMismatch = currMismatch;
				currMismatch = prevMismatch;
			}
		
		}
	}
	return mismatch == 2 && s1[prevMismatch] == s2[currMismatch] && s1[currMismatch] == s2[prevMismatch];
}

int main(){
	string s = "abc";
	string s2 = "def";
	cout<<s<<" "<<s2<<" "<<checkIfSingleSwap(s,s2)<<endl;
	cout<<"amer"<<" "<<"rmea"<<" "<<checkIfSingleSwap("amer","rmea")<<endl;
	return 0;
}
