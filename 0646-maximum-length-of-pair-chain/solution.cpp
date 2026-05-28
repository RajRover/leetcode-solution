class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int idx,int p,vector<vector<int>>& pairs){
    //     if(idx>=pairs.size()) return 0;
    //     if(dp[idx][p+1]!=-1) return dp[idx][p+1];
    //     int take=0;
    //     if(p==-1 || pairs[idx][0]>pairs[p][1]){
    //         take=1+solve(idx+1,idx,pairs);
    //     }
    //     int skip=solve(idx+1,p,pairs);
    //     return dp[idx][p+1]=max(skip,take);
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        // dp.resize(pairs.size(),vector<int>(pairs.size(),-1));
        // return solve(0,-1,pairs);
        //dp[i] max chains ending at i index
        vector<int>dp(pairs.size(),1);
        int res=1;
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                    res=max(res,dp[i]);
                }
            }
        }
        return res;
    }
};
