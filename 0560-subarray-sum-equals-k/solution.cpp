class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> f;
        int res=0;
        f[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i]; 
            res+=f[sum-k];
            f[sum]++;
        }
        return res;
    }
};
