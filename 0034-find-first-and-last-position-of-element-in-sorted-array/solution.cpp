class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb==n || nums[lb]!=target){
            return {-1,-1};
        }
        return {lb,ub-1};
        // int low=0;
        // int high=n-1;
        // int res1=0;
        // int res2=0;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]<target) low=mid+1;
        //     else if(nums[mid]>target) high=mid-1;
        //     else{
        //         res1=mid;
        //         high=mid-1;
        //     }
        // }
        // low=0;
        // high=n-1;
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]<target) low=mid+1;
        //     else if(nums[mid]>target) high=mid-1;
        //     else{
        //         res2=mid;
        //         low=mid+1;
        //     }
        // }
        // if(res1==n || nums[res1]!=target) return {-1,-1};
        // return {res1,res2};
     }
};
