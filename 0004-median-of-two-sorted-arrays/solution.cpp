class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cnt=0;
        int i=0;
        int j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int ind_1=(n/2);
        int ind_2=(n/2)-1;
        double el_1=0;
        double el_2=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(ind_1==cnt) el_1=nums1[i];
                if(ind_2==cnt) el_2=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(ind_1==cnt) el_1=nums2[j];
                if(ind_2==cnt) el_2=nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(ind_1==cnt) el_1=nums1[i];
            if(ind_2==cnt) el_2=nums1[i];
            i++;
            cnt++;
        }
        while(j<n2){
            if(ind_1==cnt) el_1=nums2[j];
            if(ind_2==cnt) el_2=nums2[j];
            j++;
            cnt++;
        }
        if(n%2==0){
            return (el_1+el_2)/2.0;
        }
        else{
            return el_1;
        }
        return -1;
    }
};
