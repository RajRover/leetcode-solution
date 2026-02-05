class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        int fmax=0;
        int secmax=0;
        for(int i=0;i<n;i++){
            if(fmax<nums[i]){
            secmax=fmax;
            fmax=nums[i];}
            else if(secmax<nums[i]){
                secmax=nums[i];
            }
        }
        int p1=fmax*secmax;
        int fmin=INT_MAX;
        int secmin=0;
        for(int i=0;i<n;i++){
            if(fmin>nums[i]){
            secmin=fmin;
            fmin=nums[i];}
            else if(secmin>nums[i]){
                secmin=nums[i];
            }
        }
        int p2=fmin*secmin;
        return p1-p2;
    }
};
