class Solution {
public:
    // //recursion+memoization
    // int solve(vector<int>& nums,int n,int i,vector<int>&dp){
    //     if(i<0) return 0;
    //     int steal=nums[i]+solve(nums,n,i-2,dp);
    //     int skip=solve(nums,n,i-1,dp);
    //     if(dp[i]!=-1) return dp[i];
    //     return dp[i]=max(steal,skip);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n,-1);
        // return solve(nums,n,n-1,dp);
        vector<int>dp(n+1);
        //dp[i]=total stolen money till i house
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+dp[i-2];
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n];

    }
};
