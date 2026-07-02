class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int i=1;
        for(int j=2;j<nums.size();j++){
            if(nums[i-1]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
