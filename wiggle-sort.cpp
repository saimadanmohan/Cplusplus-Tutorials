vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) 
        return {};
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res;
    for (int i = 0; i < m + n - 1; i++) {
        int begin_pos = res.size();
        int row = max(0, i - n + 1);
        int col = min(i , n - 1);
        while(col >= 0 && row < m ){
            res.push_back(matrix[row][col]);
            row++;
            col--;
        }
        if (i % 2 == 0)
            reverse(res.begin() + begin_pos, res.end());
    }
    return res;
}

void wiggleSort(vector<int>& nums) {
    int n = nums.size() - 1;
    for (int i=0; i< n i++) {
        if (i%2==0 && nums[i]>nums[i+1])
            swap(nums[i], nums[i+1]);
        if (i%2==1 && nums[i]<nums[i+1])
            swap(nums[i], nums[i+1]);
    }
}