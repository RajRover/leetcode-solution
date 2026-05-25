#include <climits>

class Solution {
public:
    // vector<vector<long long>> dp;

    // long long solve(int idx, bool flag, vector<int>& nums) {
    //     if (idx >= nums.size()) return 0;

    //     if (dp[idx][flag] != LLONG_MIN)
    //         return dp[idx][flag];

    //     long long skip = solve(idx + 1, flag, nums);

    //     long long val = nums[idx];
    //     if (!flag) val = -val;

    //     long long take = solve(idx + 1, !flag, nums) + val;

    //     return dp[idx][flag] = max(skip, take);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        // dp.assign(nums.size(), vector<long long>(2, LLONG_MIN));
        // return solve(0, true, nums);
        int n=nums.size();
        // vector<vector<long long>> dp(n+1,vector<long long>(2));
        // dp[0][0]=0;
        // dp[0][1]=0;
        // dp[1][0]=nums[0];
        // dp[1][1]=0;
        ////dp[i][0] is even then takes dp[i-1][odd]-nums[i-1] and skips dp[i-1][even] and similarly
        long long even=0;
        long long odd=0;
        for(int i=1;i<=n;i++){
            // dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
            // dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
            long long new_even=max(even,odd-nums[i-1]);
            long long new_odd=max(odd,even+nums[i-1]);
            even=new_even;
            odd=new_odd;
        }
        return max(even,odd);
    }
};
