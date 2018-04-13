// The deletion distance of two strings is the minimum number of characters you need to delete in the two strings in order to get the same string. For instance, the deletion distance between "heat" and "hit" is 3:

// By deleting 'e' and 'a' in "heat", and 'i' in "hit", we get the string "ht" in both cases.
// We cannot get the same string from both strings by deleting 2 letters or fewer.
// Given the strings str1 and str2, write an efficient function deletionDistance that returns the deletion distance between them. Explain how your function works, and analyze its time and space complexities.


// input:  str1 = "dog", str2 = "frog"
// output: 3

// input:  str1 = "some", str2 = "some"
// output: 0

// input:  str1 = "some", str2 = "thing"
// output: 9

// input:  str1 = "", str2 = ""
// output: 0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int deletionDistance2( const string& str1, const string& str2,int i,int j){
  if(i == -1 )
    return j+1;
  else if(j == -1)
    return i+1;
  else if(str1[i] == str2[j])
    return deletionDistance2(str1,str2,i-1,j-1);
  else if(str1[i] != str2[j])
    return 1+min(deletionDistance2(str1,str2,i-1,j),deletionDistance2(str1,str2,i,j-1));
} 
  

int deletionDistance( const string& str1, const string& str2 ) 
{
  vector<vector<int> > dp(str1.size()+1,vector<int>(str2.size()+1,0));
  for(int i = 0;i < dp.size();i++){
    for(int j = 0; j < dp[i].size();j++){
      if(i == 0)
        dp[i][j] = j;//it is the cost for deletion
      else if(j == 0)
        dp[i][j] = i;
      else if(str1[i-1] == str2[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }else
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
  //return deletionDistance2(str1,str2,str1.size()-1,str2.size()-1);
}

int main() {
  string str1 = "";
  string str2 = "";
  cout<<deletionDistance(str1,str2);
  return 0;
}