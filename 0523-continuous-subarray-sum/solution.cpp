class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> f;
        int rem=0;
        int res=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem==0){res=max(i+1,res); continue;}
            //nhi
            if(f.find(rem)==f.end()){
                f[rem]+=i;
            }
            else{
                int len=i-f[rem];
                res=max(len,res);
            }
            
        }
        return (res<2)?false:true;
    }
};
