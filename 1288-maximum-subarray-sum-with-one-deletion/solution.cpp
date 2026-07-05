class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans=arr[0];
        int power=0;
        int nopower=arr[0];
        for(int i=1;i<arr.size();i++){
            int v1=arr[i];
            int v2=arr[i]+nopower;
            int v3=arr[i]+power;
            int v4=nopower;
            int best=max(v1,v2);
            int best2=max(v3,v4);
            ans=max(ans,best);
            ans=max(ans,best2);
            nopower=best;
            power=best2;
        }
        return ans;
    }
};
