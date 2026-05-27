class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best=nums[0];
        int ans=best;
        for(int i=1;i<nums.size();i++){
            int v1=best+nums[i];
            int v2=nums[i];
            best=max(v1,v2);
            ans=max(best,ans);
        }
        return ans;
    }
};
