class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxL = 1;
        int startIdx = 0;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true; // Every character is a palindrome by itself
        }

        for (int end = 1; end < n; end++) {
            for (int start = 0; start < end; start++) {
                if (s[start] == s[end]) {
                    if (end - start <= 2 || dp[start + 1][end - 1]) {
                        dp[start][end] = true;

                        int curLen = end - start + 1;
                        if (curLen > maxL) {
                            maxL = curLen;
                            startIdx = start;
                        }
                    }
                }
            }
        }

        return s.substr(startIdx, maxL);
    }
};
