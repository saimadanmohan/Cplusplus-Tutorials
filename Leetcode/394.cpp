class Solution {
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    void appendToResult(int repeatCount, string subString, string& ans) {
        for(int i = 1; i <= repeatCount; i++) {
            ans += subString;
        }
    }
    int getRepeatCount(string s, int index, string& temp) {
        int i = 0;
        while(isNumber(s[i])) {
            temp = temp + s[i];
            i++;
        }
        return i - 1;
    }
    int getNumber(string s) {
        int val = 0;
        for(auto c: s) {
            val = val * 10 + (c - '0');
        }
        return val;
    }
public:
    string decodeString(string s) {
        stack<string> stck;
        string strToRepeat = "";
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(isNumber(c)) {
                if(strToRepeat.size() > 0) {
                    stck.push(strToRepeat);
                    strToRepeat = "";
                }
                string repeatCountString = "";
                i = getRepeatCount(s, i, repeatCountString);
                stck.push(repeatCountString);
            }else if(c == ']') {
                while(!stck.empty() && !isNumber(stck.top()[0])) {
                    strToRepeat = stck.top() + strToRepeat;
                    stck.pop();
                }
                if(stck.empty()) {
                    stck.push(strToRepeat);
                    strToRepeat = "";
                    continue;
                }
                int repeatCount = getNumber(stck.top());
                stck.pop();
                string newStr = "";
                appendToResult(repeatCount, strToRepeat, newStr);
                stck.push(newStr);
                strToRepeat = "";
            }  else if(c != '['){
                strToRepeat += c;
            } 
        }
        string ans = "";
        while(!stck.empty()) {
            ans += stck.top();
            stck.pop();
        }
        return ans + strToRepeat;
    }
};