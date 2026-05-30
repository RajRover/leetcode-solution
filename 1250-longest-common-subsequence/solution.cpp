class Solution {
public:
    // //memoization
    // vector<vector<int>>dp;
    // //recursion
    // int solve(string text1, string text2,int i,int j){
    //     int n=text1.size();
    //     int m=text2.size();
    //     if(i>=n || j>=m) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i]==text2[j]){
    //         return dp[i][j]=1+solve(text1,text2,i+1,j+1);
    //     }
    //     return dp[i][j]=max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // dp.resize(n,
        // vector<int>(m,-1));
        // return solve(text1,text2,0,0);
        //dp[i][j] is lcs for s1 of length i and s2 of lenght j
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
