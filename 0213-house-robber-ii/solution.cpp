class Solution {
public:
//memoization+recursion
    // int solve(vector<int>& nums,int n,int i,vector<int>&dp,int start){
    //     if(i<start) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int steal=nums[i]+solve(nums,n,i-2,dp,start);
    //     int skip=solve(nums,n,i-1,dp,start);
    //     return dp[i]=max(steal,skip);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // if(n==1) return nums[0];
        // vector<int> dp1(n, -1);
        // vector<int> dp2(n, -1);

        // int case1 = solve(nums, n, n - 2, dp1, 0); // exclude last
        // int case2 = solve(nums, n, n - 1, dp2, 1); // exclude first

        // return max(case1, case2);

        //bottom up
        if (n == 1) return nums[0];
        //case 1
        int prev_1=nums[0];;
        int prev_2=0;
        for(int i=1;i<n-1;i++){
            int steal=nums[i]+prev_2;
            int skip=prev_1;
            int temp=max(steal,skip);
            prev_2=prev_1;
            prev_1=temp;
        }
        int res1=prev_1;
        //case 2
        prev_1=nums[1];;
        prev_2=0;
        for(int i=2;i<n;i++){
            int steal=nums[i]+prev_2;
            int skip=prev_1;
            int temp=max(steal,skip);
            prev_2=prev_1;
            prev_1=temp;
        }
        int res2=prev_1;
        return max(res1,res2);
    }
};
