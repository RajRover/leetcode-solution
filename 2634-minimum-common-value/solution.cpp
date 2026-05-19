class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i>=0 && i<n && j>=0 && j<m){
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else break;
        }
        return (i==n || j==m)?-1:nums1[i];
    }
};
