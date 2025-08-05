class Solution {
public:
    int longestCommonSubsequence(string s, string srev) {
        int m=s.length();
        int n= srev.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) {
                    dp[i][j] =0;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == srev[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] =max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string srev = s;
        reverse(srev.begin(), srev.end());
        int result = longestCommonSubsequence(s, srev);
        return result;
    }
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};