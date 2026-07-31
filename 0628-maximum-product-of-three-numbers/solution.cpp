class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // //brute
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // //nums[0]*nums[1] is largest two product and when multiplied by largest number in end
        // return max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);

        int f_max=INT_MIN;
        int s_max=INT_MIN;
        int t_max=INT_MIN;
        int f_min=INT_MAX;
        int s_min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<f_min){
                s_min=f_min;
                f_min=nums[i];
            }
            else if(nums[i]<s_min){
                s_min=nums[i];
            }
            if(nums[i]>f_max){
                t_max=s_max;
                s_max=f_max;
                f_max=nums[i];
            }
            else if(nums[i]>s_max){
                t_max=s_max;
                s_max=nums[i];
            }
            else if(nums[i]>t_max){
                t_max=nums[i];
            }
        }
        return max(1LL*f_max*s_max*t_max,1LL*f_max*f_min*s_min);

    }
};
