class Solution {
public:
    // vector<vector<int>>dp;
    // int solve(int idx,int p,vector<int>& nums){
    //     if(idx>=nums.size()) return 0;
    //     if(dp[idx][p+1]!=-1 ) return dp[idx][p+1];
    //     int take=0;
    //     if(p==-1 || nums[idx]>nums[p]){
    //         take=1+solve(idx+1,idx,nums);
    //     }
    //     int skip=solve(idx+1,p,nums);
    //     return dp[idx][p+1]=max(take,skip);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // dp.resize(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solve(0,-1,nums);
        //dp[i] is LoLIS ending at index i;
        //bottom up
        // vector<int>dp(nums.size(),1);
        // int res=1;
        // for(int i=1;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]){
        //             dp[i]=max(dp[i],1+dp[j]);
        //             res=max(res,dp[i]);
        //         }
        //     }
        // }
        // return res;
        //patience sorting
        vector<int>ps;
        for(int i=0;i<nums.size();i++){
            if(ps.empty()){
                ps.push_back(nums[i]);
            }
            //for ps[j]>nums[i]
            int j = lower_bound(ps.begin(), ps.end(), nums[i]) - ps.begin();
            if(j==ps.size()){
                ps.push_back(nums[i]);
            }
            else ps[j]=nums[i];
        }
        return ps.size();
    }
};
