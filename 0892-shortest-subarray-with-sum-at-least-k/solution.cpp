class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq;
        vector<long long>cum_sum(nums.size(),0);
        int j=0;
        int res=INT_MAX;
        while(j<nums.size()){
            if(j==0) cum_sum[j]=nums[j];
            else{
                cum_sum[j]=cum_sum[j-1]+nums[j];
            }
            if(cum_sum[j]>=k) res=min(j+1,res);
            while(!dq.empty() && (cum_sum[j]-cum_sum[dq.front()])>=k){
                res=min(j-dq.front(),res);
                dq.pop_front();
            }
            while(!dq.empty() && cum_sum[j]<=cum_sum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return (res==INT_MAX)?-1:res;
    }
};
