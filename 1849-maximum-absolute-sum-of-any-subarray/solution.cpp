class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_ans=nums[0];
        int max_ans=nums[0];
        int ans=abs(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            min_ans=min(nums[i],min_ans+nums[i]);
            max_ans=max(nums[i],max_ans+nums[i]);
            ans=max(ans,max(abs(min_ans),max_ans));
        }
        return ans;

    }
};
