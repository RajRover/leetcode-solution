class Solution {
public:
    // vector<vector<int>>dp;
    // bool solve(int n,vector<int>&nums,int sum){
    //     if(sum==0) return true;
    //     if(n==0) return false;
    //     if(dp[n][sum]!=-1) return dp[n][sum];
    //     bool skip=solve(n-1,nums,sum);
    //     bool take=false;
    //     if(nums[n-1]<=sum){
    //         take=solve(n-1,nums,sum-nums[n-1]);
    //     }
    //     return dp[n][sum]=skip||take;
    // }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum % 2 != 0) return false;
        sum=sum/2;
        // vector<vector<bool>>dp(nums.size()+1,vector<bool>(sum+1,false));
        // for(int i=0;i<dp.size();i++){
        //     dp[i][0]=true;
        // }
        vector<bool>prev(sum+1,false);
        vector<bool>curr(sum+1,true);
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool skip=prev[j];
                bool take=false;
                if(nums[i-1]<=j){
                    take=prev[j-nums[i-1]];
                }
                curr[j]=skip||take;
            }
            prev=curr;
        }
        // return dp[nums.size()][sum];
        return prev[sum];
    }
};
