class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<arr[mid+1] && mid<n) low=mid+1;
            else if(arr[mid]<arr[mid-1] && mid>0) high=mid-1;
            else {ans=mid; break;}
        }
        return ans;
    }
};
