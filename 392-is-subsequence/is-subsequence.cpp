class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n= text2.length();
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
                if(text2[i-1] == text1[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] =max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }


    bool isSubsequence(string s, string t) {
         int len = longestCommonSubsequence(s,t);
         if(len ==s.length()){
            return true;
         }else{
            return false;
         }
    }
};