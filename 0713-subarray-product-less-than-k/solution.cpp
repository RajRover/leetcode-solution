class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int prod=1;
        int ans=0;
        while(j<n){
            prod=1ll*prod*nums[j];
            //jab tak galat
            while(prod>=k && i<=j){
                prod/=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};
