class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());  // Sort the input array
        set<vector<int>> s;  // To store unique triplets
        vector<vector<int>> output;  // Output vector

        // Iterate through the sorted array
        for (int i = 0; i < nums.size(); i++) {  
            // Two-pointer approach
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];  // Declare and compute sum

                if (sum == target) {
                    // Insert triplet into set to avoid duplicates
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;  // Move both pointers
                } 
                else if (sum < target) {
                    j++;  // Increase the left pointer to get a larger sum
                } 
                else {
                    k--;  // Decrease the right pointer to get a smaller sum
                }
            }
        }

        // Transfer the unique triplets from the set to the output vector
        for (auto triplet : s) {
            output.push_back(triplet);
        }
        
        return output;
    }
};
