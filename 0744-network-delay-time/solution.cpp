class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto&v:times){
            int a=v[0];
            int b=v[1];
            int c=v[2];
            adj[a].push_back({c,b});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto&v:adj[u]){
                int nbr=v.second;
                int dis=v.first;
                if(dis+d<dist[nbr]){
                    dist[nbr]=d+dis;
                    pq.push({d+dis,nbr});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return (ans==INT_MAX)?-1:ans;


    }
};
