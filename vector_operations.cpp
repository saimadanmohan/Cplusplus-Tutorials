class Compare {
    public:
        bool operator()(const pair<string,int>& pr1, const pair<string,int>& pr2) {
            return pr1.second == pr2.second ?
                lexicographical_compare(pr1.first.begin(), pr1.first.end(), pr2.first.begin(), pr2.first.end()) :
                pr1.second > pr2.second;  
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        for(auto word: words) {
            freq[word]++;
        }
        vector<pair<string, int> > vec;
        vec.insert(vec.begin(), freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), Compare());
        vector<string> result;
        for(int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};