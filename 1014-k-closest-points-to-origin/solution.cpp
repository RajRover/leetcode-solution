struct cmp{
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<points.size();i++){
            mp[i]=1LL*points[i][0]*points[i][0]+1LL*points[i][1]*points[i][1];
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int idx=pq.top().second;
            ans.push_back({points[idx][0],points[idx][1]});
            pq.pop();
        }
        return ans;
    }
};
