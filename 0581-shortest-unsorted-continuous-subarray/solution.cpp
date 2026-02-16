class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<n-1){
            if(nums[start+1]<nums[start]) break;
            else start++;
        }
        if(start==n-1) return 0;
        while(end>0){
            if(nums[end-1]>nums[end]) break;
            else end--;
        }
        int mini=*min_element(nums.begin()+start,nums.begin()+end+1);
        int maxi=*max_element(nums.begin()+start,nums.begin()+end+1);
        while(start>0 && nums[start-1]>mini) start--;
        while(end<n-1 && nums[end+1]<maxi) end++;
        return end-start+1;
    }
};
