class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        //two pointer is better 
        // // Create a vector of pairs where each pair is (element, original index)
        // vector<pair<int, int>> indexedNums;
        // for (int i = 0; i < n; i++) {
        //     indexedNums.push_back({nums[i], i});
        // }
        
        // // Sort the array by the element values
        // sort(indexedNums.begin(), indexedNums.end());

        // int left = 0;
        // int right = n - 1;
        // vector<int> ans;

        // while (left < right) {
        //     int sum = indexedNums[left].first + indexedNums[right].first;

        //     if (sum == target) {
        //         ans.push_back(indexedNums[left].second);  // Original index of the left pointer
        //         ans.push_back(indexedNums[right].second); // Original index of the right pointer
        //         return ans;
        //     } else if (sum < target) {
        //         left++; // Move the left pointer to the right
        //     } else {
        //         right--; // Move the right pointer to the left
        //     }
        // }

        // return ans; // Return empty vector if no solution is found

        // hashmap is best
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            int complement  = target-nums[i];
            if(mpp.count(complement)){
                return {mpp[complement],i};
            }
            mpp[nums[i]] = i;
        }
        return {};




    }
};