class Solution {
public:
    void bfs(unordered_map<int,vector<int>> &adj,vector<bool> &vis,int &dist,int&farthest,int node){
        queue<int> q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int size=q.size();
            dist++;
            while(size--){
                int u=q.front();
                farthest=u;
                q.pop();
                for(auto&v:adj[u]){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }

    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        if(!edges1.size() && !edges2.size()) return 1;
        unordered_map<int,vector<int>> adj1;
        for(auto&edge:edges1){
            int u=edge[0];
            int v=edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<bool> vis1(adj1.size()+1,false);
        int dist1=-1;
        int farthest=0;
        bfs(adj1,vis1,dist1,farthest,0);
        vis1.assign(adj1.size()+1,false);
        dist1=-1;
        bfs(adj1,vis1,dist1,farthest,farthest);

        unordered_map<int,vector<int>> adj2;
        for(auto&edge:edges2){
            int u=edge[0];
            int v=edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<bool> vis2(adj2.size()+1,false);
        int dist2=-1;
        int farthest2=0;
        bfs(adj2,vis2,dist2,farthest2,0);
        vis2.assign(adj2.size()+1,false);
        dist2=-1;
        bfs(adj2,vis2,dist2,farthest2,farthest2);
        int D=max(dist1,dist2);
        int res=ceil(dist1/2.0)+ceil(dist2/2.0)+1;
        res=max(res,D);
        return res;
    }
};
