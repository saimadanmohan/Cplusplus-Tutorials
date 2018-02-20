class Solution {
public:
    void lefttrim(string &s){
        int  i;
        for(i=0;i<s.size();i++)
            if(s[i] != ' ') break;
        s.erase(0,i);
    }
   void righttrim(string &s){
        int  i;
        for(i=s.size() - 1 ;i>= 0;i--)
            if(s[i] != ' ') break;
        s.erase(i+1,s.size() - i);
    }


    string reverseString(string &s) {
        lefttrim(s);
        righttrim(s);
        int curr = 0;
        for(int i=0;i<s.size();i++)
            if(s[i]!= ' '  || (s[i] ==' ' && s[i-1]!= ' '))
                s[curr++] = s[i];
        
        s = s.substr(0,curr);

        int i = 0;
        int j= s.size() - 1;

       while(i<j)
            swap(s[i++],s[j--]);
        for(int i=0,j = 0;i<s.size();i++){
            if(s[i] == ' ' || i== s.size()-1){
                int temp = i -1;
                if( i == s.size() - 1)
                    temp = i;
                while(j< temp)
                    swap(s[j++],s[temp--]);
                j = i+1;
            }
        }
        return s;
    }
};