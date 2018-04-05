class Solution {
public:
    struct lexo_sort {
        map<int,long> ten_power_map;
        lexo_sort(map<int,long> ten_power_map) { this->ten_power_map = ten_power_map; }
        bool operator () (int num1, int num2) { 
            long pow1 = ten_power_map[num1];
            long pow2 = ten_power_map[num2];
            int prev1 = 0;
            int prev2 = 0;
            while(num1 && num2){
                if(num1/pow1 != num2/pow2)
                    return num1/pow1 > num2/pow2;
                prev1 = num1/pow1;
                prev2 = num2/pow2;
                num1 %= pow1;
                num2 %= pow2;
                pow1 /= 10;
                pow2 /= 10;
            }
            if(!num1)return prev1 < num2/pow2;  
            if(!num2)return prev2 < num1/pow1;
            return num1<num2;
        }
    };
    
    int get_ten_power(int num){
        long val = 1;
        while(val*10 < num)
            val *= 10;
        return val;
    }
    

    string largestNumber(vector<int>& nums) {
        map<int,long> ten_power_map;
        vector<int> result(nums.size())l
        for(int i=0;i<nums.size();i++)
            ten_power_map[nums[i]] = get_ten_power(nums[i]); 
        //for(int i=0;i<nums.size();i++)
        //    cout<<ten_power_map[nums[i]]<<" ";
        //cout<<endl;
        sort(nums.begin(),nums.end(),lexo_sort(ten_power_map));
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        return "";
    }
};