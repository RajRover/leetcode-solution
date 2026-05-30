class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n,1);
      vector<int>prev(n,-1);
      sort(nums.begin(), nums.end());
      for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i] % nums[j] == 0 && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                prev[i]=j;
            }
        }
      }
      int max_ind=0;
      for(int i=1;i<n;i++){
        if(dp[i]>dp[max_ind]){
            max_ind=i;
        }
      }
      vector<int>res;
      while(max_ind!=-1){
        res.push_back(nums[max_ind]);
        max_ind=prev[max_ind];
      }
      return res;
    }
};

