class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_best=nums[0];
        int min_best=nums[0];
        int ans=max_best;
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*max_best;
            int v3=nums[i]*min_best;
            max_best=max(v1,v2);
            max_best=max(max_best,v3);
            min_best=min(v1,v3);
            min_best=min(v2,min_best);
            ans=max(max_best,ans);
        }
        return ans;
    }
};
