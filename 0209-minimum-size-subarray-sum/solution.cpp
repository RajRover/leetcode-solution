class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int sum = 0;
        int res=n+1;
        for(int high=0;high<n;high++){
            sum=sum+nums[high];
            while(sum>=target){
                int len=high-low+1;
                res=min(res,len);
                sum=sum-nums[low];
                low++;
            }
        }
        return (res==n+1)?0:res;
    }
};
