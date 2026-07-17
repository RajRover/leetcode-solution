class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cost=0;
        long long cnt=0;
        long long avl=k;
        long long mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>avl){
                long long needed = nums[i] - avl;
                long long ops = (needed + k - 1) / k;
                cnt+=ops;
                long long start = (cnt - ops + 1);
                long long end = cnt;
                //$(cnt + 1) + (cnt + 2) + \dots + (cnt + ops)$
                long long range_sum = ((start + end) % mod * (ops % mod)) % mod;
                cost = (cost + range_sum * 500000004) % mod;
                avl+=ops*k;
            }
            avl=avl-nums[i];
        }
        return (int)cost;
    }
};
