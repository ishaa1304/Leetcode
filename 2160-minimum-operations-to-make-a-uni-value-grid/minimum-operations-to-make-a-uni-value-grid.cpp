class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto const&row:grid)
        {
            for(int num:row)
            {
                nums.push_back(num);
            }
        }
        sort(nums.begin(), nums.end());
        int median= nums[nums.size()/2];
        int count =0;
        for(int num: nums){
            if((num-median)%x !=0){
                return -1;
            }
            count += abs(num-median)/x;

        }
        return count;
    }
};