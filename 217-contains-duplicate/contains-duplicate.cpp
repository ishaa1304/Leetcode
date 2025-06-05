class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            if (mpp[num] > 0) return true;  // Duplicate found
            mpp[num]++;
        }
        return false;  // No duplicates
    }
};
