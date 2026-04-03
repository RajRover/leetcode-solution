class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int sum=0;
        int cnt=0;
        int low=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[low];
                low++;
            }
            cnt+=i-low+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        //prefix sum==k
        int diff=atmost(nums,k)-atmost(nums,k-1);
        return diff;
    }
};
