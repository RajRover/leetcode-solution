class Solution {
public:
    // vector<vector<int>>dp;
    // int solve(string word1, string word2,int i,int j){
    //     int n=word1.size();
    //     int m=word2.size();
    //     if(i<0){
    //         return j+1;
    //     }
    //     if(j<0){
    //         return i+1;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if (word1[i] == word2[j]) {
    //         return dp[i][j]=solve(word1, word2, i-1, j-1);
    //     }
    //     return dp[i][j]=1 + min({
    //     solve(word1, word2, i - 1, j),     // Delete
    //     solve(word1, word2, i, j - 1),     // Insert
    //     solve(word1, word2, i - 1, j - 1)  // Replace
    // });
    // }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //dp.resize(n,vector<int>(m,-1));
        //return solve(word1,word2,n-1,m-1);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};
