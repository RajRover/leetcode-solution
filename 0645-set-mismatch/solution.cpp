class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int add=(1LL*n*(n+1))/2-accumulate(nums.begin(),nums.end(),0LL);;
        vector<int>cnt(n + 1, 0);
        int duplicate=-1;
        for(int num:nums){
            cnt[num]++;
            if(cnt[num]==2){
                duplicate=num;
                break;
            }
        }
        return {duplicate,(int)(duplicate+add)};
        
    }
};
