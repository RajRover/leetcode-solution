class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete=INT_MIN;
        int n=arr.size();
        int v=0;
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int prevno=nodelete;
            int prevone=onedelete;
            nodelete=max(arr[i],nodelete+arr[i]);
            if(onedelete==INT_MIN){
                v=arr[i];
            }
            else{
                v=prevone+arr[i];
            }
            onedelete=max(v,prevno);
            ans=max(ans,max(onedelete,nodelete));
        }
        return (ans<0)?*max_element(arr.begin(),arr.end()):ans;
    }
};
