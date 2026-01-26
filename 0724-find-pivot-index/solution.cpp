class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int left=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0) left=left+nums[i-1];
            int right=sum-nums[i]-left;
            if(left==right) return i;
        }
        return -1;
    }
};
