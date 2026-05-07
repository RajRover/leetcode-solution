class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        const int MOD = 1e9+7;
        vector<long long> power(n);
        power[0] = 1;

        for(int i=1;i<n;i++){
            power[i] = (power[i-1] * 2LL) % MOD;
        }
        int low=0;
        int high=n-1;
        while(low<=high){
            if(nums[low]+nums[high]<=target){
                cnt = (cnt + power[high-low]) % MOD;
                low++;
            }
            else high--;
        }
        return cnt;
    }
};
