class Solution {
public:
    vector<int> dp;
    int solve(int idx,vector<int>& points){
        if(idx>=points.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=points[idx]+solve(idx+2,points);
        int skip=solve(idx+1,points);
        return dp[idx]=max(take,skip);     
    }
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>points(mx+1,0);
        for(int i=0;i<nums.size();i++){
            points[nums[i]]+=nums[i];
        }
        dp.resize(points.size(),-1);
        return solve(0,points);
    }
};
