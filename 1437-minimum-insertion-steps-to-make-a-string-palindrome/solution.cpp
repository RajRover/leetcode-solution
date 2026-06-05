class Solution {
public:
    // vector<vector<int>>dp;
    // int solve(string s,int i,int j){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j]){
    //         return dp[i][j]=solve(s,i+1,j-1);
    //     }
    //     return dp[i][j]=1+min(solve(s,i+1,j),solve(s,i,j-1));
    // }
    int minInsertions(string s) {
        // int n=s.size();
        // dp.resize(n,vector<int>(n,-1));
        // return solve(s,0,n-1);

        //dp[i][j]:min insertion from i to j;
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);}
            }
        }
        return dp[0][n-1];
    }
};
