class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        int cnt=0;
        for(int i=0;i<n;i++){
            int k=n-i-1;
            int req=total-sum-nums[i];
            if(k!=0 && nums[i]>(req/k) ) cnt++;
            sum+=nums[i];
        }
        return cnt;
    }
};
