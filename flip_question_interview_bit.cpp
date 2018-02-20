vector<int> Solution::flip(string A) {
    if(A.empty()) return {};
    vector<int> maxArr(A.size());
    for(int i=0;i<A.size();i++){
        if(A[i] == '1')
            maxArr[i] = -1;
        else
            maxArr[i] = 1;
    }
    int running_sum = 0;
    int max_sum = 0;
    int left = 0;
    vector<int> ans = {-1,-1};
    for(int i=0;i<maxArr.size();i++){
        if(running_sum + maxArr[i] < 0 ){
            left = i+1;
            running_sum = 0;
        }else
            running_sum += maxArr[i];
        if(running_sum > max_sum){
            ans[0] = left+1;
            ans[1] = i+1;
            max_sum = running_sum;
        }
    }
    if(ans[0] == -1)
        return {};
    else
        return ans;
}
