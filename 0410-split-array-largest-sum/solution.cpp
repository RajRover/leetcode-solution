class Solution {
public:
    int fn(vector<int>& nums, int mid){
        int n=nums.size();
        int cnt=1;
        int numbers=0;
        for(int i=0;i<n;i++){
            if(nums[i]+numbers<=mid){
                numbers+=nums[i];
            }
            else{
                cnt++;
               numbers=nums[i]; 
            }
        }
        return cnt;
            }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=fn(nums,mid);
            if(cnt>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
