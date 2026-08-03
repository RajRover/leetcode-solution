class Solution {
public:
    bool possible(int k,int guess,vector<int>& nums){
        int cnt=1;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum+nums[i]<=guess){
                sum+=nums[i];
                continue;
            }
            cnt++;
            sum=nums[i];
        }
        if(cnt>k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(k,mid,nums)){
                ans=mid;
                high=mid-1;     
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
