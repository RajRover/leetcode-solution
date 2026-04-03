class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //hashmap
        unordered_map<int,int>f;
        f[0]=1;
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int qs=sum-k;
            int freq=f[qs];
            res+=freq;
            f[sum]++;
        }
        return res;
    }
};
