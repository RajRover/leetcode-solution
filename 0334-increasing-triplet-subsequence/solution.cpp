class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //brute force
        // int cnt=0;
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(cnt==3) return true;
        //         if(nums[i]<nums[j]){
        //             cnt++;    
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        // }
        // return false;
        int num1=INT_MAX;
        int num2=INT_MAX;
        for(int num3:nums){
            if(num3<=num1){
                num1=num3;
            }
            else if(num3<num2){
                num2=num3;
            }
            else if(num3>num1 && num3>num2){
                return true;
            }
        }
        return false;
    }
};
