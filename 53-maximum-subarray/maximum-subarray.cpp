class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long sum =0;
        int start=0;
        int ansStart = -1,ansEnd =-1;

        for(int i=0;i<nums.size();i++){
            if(sum ==0){
                start=i;
            }

            sum +=nums[i];

            if(sum>maxi){
                maxi = sum;
                ansStart  = start;
                ansEnd = i;

            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};