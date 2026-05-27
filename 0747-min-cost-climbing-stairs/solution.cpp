class Solution {
public:
    // vector<int>dp;
    // int solve(vector<int>& cost,int idx){
    //     if(idx>=cost.size()) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     int one_step=cost[idx]+solve(cost,idx+1);
    //     int two_step=cost[idx]+solve(cost,idx+2);
    //     return dp[idx]=min(one_step,two_step);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        //dp.resize(cost.size(),-1);
        //return min(solve(cost,0),solve(cost,1));
        //bottom up
        int n=cost.size();
        //vector<int> dp(n+1);
        //dp[0]=0;
        int a=0;
        //dp[1]=0;
        int b=0;
        //dp[i] is min cost took to reach stair i (excluding i)
        for(int i=2;i<=n;i++){
            int one_step=b+cost[i-1];
            int two_step=a+cost[i-2];
            int c=min(one_step,two_step);
            a=b;
            b=c;
        }
        return b;//dp[n];
    }
};
