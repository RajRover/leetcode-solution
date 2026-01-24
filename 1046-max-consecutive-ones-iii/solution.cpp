class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int res=0;
        int cnt1=0;
        for(int high=0;high<n;high++){
            if(nums[high]==1) cnt1++;
            int len=high-low+1;
            int diff=len-cnt1;
            while(diff>k){
                if(nums[low]==1) cnt1--;
                low++;
                len=high-low+1;
                diff=len-cnt1;
            }
            len=high-low+1;
            res=max(res,len);
        }
        return res;
    }
};
