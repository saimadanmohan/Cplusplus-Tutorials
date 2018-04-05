class Solution {
    struct cmp {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        }  
    };
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<int> v;
        for(int i=0;i<people.size();i++) v.push_back(i);
        vector<pair<int, int>> res(people.size());
        sort(people.begin(), people.end(), cmp());
        for(auto &a:people) {
            res[v[a.second]] = a;
            v.erase(v.begin()+a.second);
        }
        return res;
    }
};

class Solution {
public:
    
    static bool compare_heights(const pair<int, int>& a,const pair<int, int>& b) {
        if(a.first != b.first)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),compare_heights);
        int sz = people.size();
        for(int i=0;i<sz;i++){
            pair<int, int> curr_pair = people[i];
            if(curr_pair.second != i){
               // people.erase(people.begin()+i);
                for(int pos = i;pos>curr_pair.second;pos--)
                    people[pos] = people[pos-1];
                people[curr_pair.second] = curr_pair;
                //people.insert(people.begin()+curr_pair.second,curr_pair);
            }
        }
        return people;
    }
};