class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> sum;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if (sum.find(target-nums[i])!=sum.end()){
                result.push_back(i);
                result.push_back(sum[target-nums[i]]);
            }
            sum[nums[i]] = i;
        }
        return result;

    }
};
