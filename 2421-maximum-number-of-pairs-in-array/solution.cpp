class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<int> ans;
        int cnt=0;
        for(auto it:mp){
           cnt+=it.second/2;
        }
        int n=nums.size();
        ans.push_back(cnt);
        ans.push_back(n-(2*cnt));
        return ans;
    }
};
