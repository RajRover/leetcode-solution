class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
            while (res.size() >= 2 &&
               res.back() == res[res.size() - 2]){
                long long val=res.back();
                res.pop_back();
                val+=res.back();
                res.pop_back();
                res.push_back(val);
               }
        }
        return res;
    }
};
