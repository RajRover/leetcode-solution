class Solution {
public:
    // void left_max(vector<int>& height,vector<int>&left){
    //     int n=height.size();
    //     left[0]=height[0];
    //     for(int i=1;i<n;i++){
    //         left[i]=max(left[i-1],height[i]);
    //     }
    // }
    // void right_max(vector<int>& height,vector<int>&right){
    //     int n=height.size();
    //     right[n-1]=height[n-1];
    //     for(int i=n-2;i>=0;i--){
    //         right[i]=max(right[i+1],height[i]);
    //     }
    // }
    int trap(vector<int>& height) {
        //min(righ_max,left_max)-nums[i]
        int n=height.size();
        if(n==0) return n;
        // vector<int>left(n);
        // vector<int>right(n);
        // left_max(height,left);
        // right_max(height,right);
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans+=abs(min(left[i],right[i])-height[i]);
        // }
        // return ans;
        int left=0,right=n-1;
        int left_max=0,right_max=0;
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){
                if(left_max<=height[left]){
                    left_max=height[left];
                }
                else{
                    ans+=left_max-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=right_max){
                    right_max=height[right];
                }
                else{
                    ans+=right_max-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
