#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
void getTokens(string version,vector<string>& toks){
    std::istringstream iss(version);
    std::string token;
    while (getline(iss, token, '.'))
        toks.push_back(token);
}
int compareVersion(string version1, string version2) {
    vector<string> v1;
    vector<string> v2;
    getTokens(version1,v1);
    getTokens(version2,v2);
    for(int i=0;i<max(v1.size(),v2.size());i++){
 
        int vs1 = i< v1.size() ? stoi(v1[i]) : 0;
        int vs2 = i< v2.size() ? stoi(v2[i]) : 0;
        if(vs1<vs2)
            return -1;
        else if(vs1>vs2)
            return 1;
    }
    return 0;
}
 
int main(){
	cout<<compareVersion("1.1","1.12")<<endl;
	return 0;
}