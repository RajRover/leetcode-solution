class Solution {
public:
    // int solve(int n,vector<int>&dp){
    //     if(n<=2) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    int climbStairs(int n) {
        ////memoization
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        if(n<=1) return n;
        int a=1;
        int b=2;
        for(int i=3;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};
