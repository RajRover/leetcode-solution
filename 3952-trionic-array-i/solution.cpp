class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int cnt=0;
        while(i+1<n && nums[i]<nums[i+1]){
            i++;
        }
        if(i==0) return false;
        while(i+1<n && nums[i]>nums[i+1]){
            cnt++;
            i++;
        }
        if(!cnt) return false;
        cnt=0;
        while(i+1<n && nums[i]<nums[i+1]){
            i++;
            cnt++;
        }
        if(!cnt) return false;
        return i==n-1;

    }
};
