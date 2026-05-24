class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>res;
        int cnt=1;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt++;
            }
            else cnt=1;
            if(cnt<=k){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
