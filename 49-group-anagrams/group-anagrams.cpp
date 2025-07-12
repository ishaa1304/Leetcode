class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for (string str : strs){
         string sorted_word = str;
            sort(sorted_word.begin(),sorted_word.end());
            mpp[sorted_word].push_back(str);

        }
        vector<vector<string>> result;
        for (auto& pair : mpp) {
            result.push_back(pair.second);
        }
        return result;
    }
};