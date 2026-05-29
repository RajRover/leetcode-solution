class Solution {
public:
    // unordered_map<string,long long> mp;
    // long long solve(int p,int idx,vector<int>&nums){
    //     if(idx>=nums.size()) return 0;
    //     string key=to_string(p)+'_'+to_string(idx);
    //     if(mp.find(key)!=mp.end()) return mp[key];
    //     long long take=0;
    //     if(p==-1 || nums[idx]>=nums[p]){
    //         take=nums[idx]+idx+solve(idx,idx+1,nums);
    //     }
    //     long long skip=solve(p,idx+1,nums);
    //     return mp[key]=max(take,skip);
    // }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        // vector<int>new_num(nums.size());
        int mx=*max_element(nums.begin(),nums.end());
        if(mx<=0) return mx;
        // for(int i=0;i<nums.size();i++){
        //     new_num[i]=nums[i]-i;
        // }        
        // return solve(-1,0,new_num);
        //bottom up
        // vector<long long> dp(nums.size(),-1);
        // for(int i=0;i<nums.size();i++){
        //     dp[i]=nums[i];
        // }
        // long long max_sum=INT_MIN;
        // for(int i=1;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]-i>=nums[j]-j){
        //             dp[i]=max<long long>(dp[i],dp[j]+nums[i]);
        //             max_sum=max(dp[i],max_sum);
        //         }
        //     }
        // }
        // return max_sum;
        map<int,long long>mp;
        long long res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int key=nums[i]-i;
            auto it=mp.upper_bound(key);
            long long sum=nums[i];
            if(it!=mp.begin()){
                it--;
                sum+=it->second;
            }
            mp[key]=max(mp[key],sum);
            it=mp.upper_bound(key);
            while(it!=mp.end() && it->second<sum){
                mp.erase(it++);
            }
            res=max(res,sum);
        }
        return res;
        
    }
};
