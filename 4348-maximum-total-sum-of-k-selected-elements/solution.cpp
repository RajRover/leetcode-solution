class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long total_sum=0;
        sort(nums.begin(),nums.end());
        long long n=nums.size();
        for(long long i=n-1;i>=n-k;i--){
            if(mul>0){
                total_sum+=1ll*mul*nums[i];
                mul--;
            }else{
                total_sum+=nums[i];
            }
        }
        return total_sum;
    }
};
