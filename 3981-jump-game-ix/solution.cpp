class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre_max(n);
        vector<int> pre_min(n);
        int max_no=0;
        for(int i=0;i<n;i++){
            max_no=max(max_no,nums[i]);
            pre_max[i]=max_no;
        }
        int min_no=INT_MAX;
        for(int i=n-1;i>=0;i--){
            min_no=min(min_no,nums[i]);
            pre_min[i]=min_no;
        }
        vector<int> ans(n);
        ans[n-1]=pre_max[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=pre_max[i];
            if(pre_min[i+1]<pre_max[i]){
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};
