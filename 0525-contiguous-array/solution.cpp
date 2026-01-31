class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int zero=0;
        int one=0;
        unordered_map<int,int> f;
        int diff=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                one++;
            }
            diff=zero-one;
            if(diff==0) 
                {ans=max(ans,i+1); 
                continue;}
            if(f.find(diff)==f.end()){
                f[diff]=i;
            }
            else{
                int len=i-f[diff];
                ans=max(len,ans);
            }

        }
        return ans;
    }
};
