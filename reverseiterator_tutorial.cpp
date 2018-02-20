class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<string> result(nums.size(),"");
        map<int,int> ordered_map;
        int max = nums[0];
        for(int i=0;i<nums.size();i++)
            ordered_map[nums[i]] = i;
        int rank =1 ; 
        for(map<int,int>::reverse_iterator player_info = ordered_map.rbegin();player_info != ordered_map.rend();player_info++ ){
            int score = player_info->first;
            int index = player_info->second;
            if(rank == 1)
                result[index] = "Gold Medal";
            else if(rank == 2)
                result[index] = "Silver Medal";
            else if(rank == 3)
                result[index] = "Bronze Medal";
            else{
                string rank_as_string = to_string(rank);
                result[index] = rank_as_string;
            }
            rank++;
        }
        return result;
    }
};