class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //case F
        map<int,int> mp;
        //build events
        for(int i=0;i<intervals.size();i++){
            mp[intervals[i][0]]++;
            //inclusive
            mp[intervals[i][1]+1]--;
        }
        int cur=0;
        int ans=0;
        for(auto &it:mp){
            cur+=it.second;
            ans=max(cur,ans);
        }
        return ans;
    }
};
