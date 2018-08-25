class Solution {
public:
    class Compare {
        //if you don't make this public, you will get irrelevant errors
        public:
            bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
                return a.second > b.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> ,vector<pair<int,int> >, Compare> freqPQ;
        for(auto it: mp) {
            freqPQ.push({it.first,it.second});
            if(freqPQ.size() > k) {
                freqPQ.pop();
            }
        }
        vector<int> ans;
        while(!freqPQ.empty()) {
            ans.push_back(freqPQ.top().first);
            freqPQ.pop();
        }
        return ans;
    }
};