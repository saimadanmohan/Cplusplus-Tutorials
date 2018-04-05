#include <iostream>
#include <bitset>
#include <string>
#include <unordered_map>
bool isStrobogrammatic(std::string &num) {
	int left = 0;
	int right = num.size() - 1;
    std::unordered_map<char,char> character_map{{'1','1'},{'6','9'},{'9','6'},{'8','8'},{'0','0'}};
    while(left<=right){
    	//std::cout<<character_map[num[left]]<<std::endl;
    	//std::cout<<character_map[num[right]]<<std::endl;
	    if(character_map.find(num[left])!=character_map.end() && character_map[num[left]] != num[right])
	        return false;
	    left++;
	    right--;
	}
	return true;
}

int main() {
	std::string s = "1881";
	std::cout<<isStrobogrammatic(s)<<std::endl;
	return 0;
}