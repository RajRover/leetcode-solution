class Solution {
public:
    double sum(vector<int>& nums,int mid){
        int n=nums.size();
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil(double(nums[i])/(double(mid)));
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sum(nums,mid)<=double(threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
