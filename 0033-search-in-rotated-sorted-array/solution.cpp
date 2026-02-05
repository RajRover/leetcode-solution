class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            //p2
            if(nums[mid]>nums[n-1]){
                if(nums[mid]<target){
                    //right
                    low=mid+1;
                }
                else{
                    if(nums[0]>target){
                        //right
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }
            else{
                if(nums[mid]>target){
                    //left
                    high=mid-1;
                }
                else{
                    if(nums[n-1]<target){
                        //left
                        high=mid-1;
                    }
                    else{
                        //right
                        low=mid+1;
                    }
                }
            }

        }
        return -1;
    }
};
