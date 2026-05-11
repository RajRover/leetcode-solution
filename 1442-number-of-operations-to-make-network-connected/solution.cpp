class Solution {
public:
    // bool dfs(unordered_map<int,vector<int>> &adj,vector<bool> &vis,int u){
    //     vis[u]=true;
    //     for(int &v:adj[u]){
    //         if(!vis[v]){
    //             dfs(adj,vis,v);
    //         }
    //     }
    //     return true;
    // }
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;//ignore
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<(n-1)) return -1;
        // unordered_map<int,vector<int>> adj(n);
        // for(auto &edge:connections){
        //     int u=edge[0];
        //     int v=edge[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        // vector<bool> vis(n,false);
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         if(dfs(adj,vis,i)){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt-1;
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);
        int connected=n;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            if(find(u)!=find(v)){
                Union(u,v);
                connected--;
            }
        }
        return connected-1;
    }
};
