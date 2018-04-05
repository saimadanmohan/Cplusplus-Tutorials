class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> hash_map;
        for(int i=0;i<s.size();i++){
            //checking if an element exists
            if(hash_map.find(s[i]-'a') == hash_map.end())
                hash_map[s[i]-'a'] = 1;
            else
                hash_map[s[i]-'a'] = hash_map[s[i]-'a'] + 1;
        }
        for(int i=0;i<t.size();i++){
            if(hash_map.find(t[i]-'a') == hash_map.end())
                return t[i];
            else{
                hash_map[t[i]-'a']  -= 1;
                //removing an element
                if(hash_map[t[i]-'a'] == 0)
                    hash_map.erase(t[i] - 'a');
            }
        }
        return '$';//error invalid input       
    }
};