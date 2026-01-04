class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       if(n==0) return 0;
       int longest=1;
       unordered_set<int> ans;
       for(int k:nums){
        ans.insert(k);
       }
       for(auto it:ans){
        if(ans.find(it-1)==ans.end()){
            int cnt=1;
            int x=it;
            while(ans.find(x+1)!=ans.end()){
                cnt++;
                x=x+1;
            }
            longest=max(longest,cnt);
        }
       }
       return longest;
    }
};
