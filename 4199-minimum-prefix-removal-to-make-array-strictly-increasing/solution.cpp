class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int low=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) continue;
            else{
                low=i+1;
            }
        }
        return low;
    }
};
