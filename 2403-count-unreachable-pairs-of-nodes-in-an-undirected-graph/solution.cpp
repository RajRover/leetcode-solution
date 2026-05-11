class Solution {
public:
    // void dfs(unordered_map<int,vector<int>> &adj,int node,vector<bool> &vis,int &size) {
    //     if(vis[node]) return;
    //     vis[node]=true;
    //     size++;
    //     //neighbous
    //     for(int &v:adj[node]){
    //         if(!vis[v]){
    //             dfs(adj,v,vis,size);
    //         }
    //     }
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        // vector<bool> vis(n,false);
        // unordered_map<int,vector<int>> adj(n);
        // for(auto &edge:edges){
        //     int u=edge[0];
        //     int v=edge[1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }
        // vector<int> size_comp;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         int size=0;
        //         dfs(adj,i,vis,size);
        //         size_comp.push_back(size);
        //     }
        // }
        // long long res = 0;
        // long long remaining = n;

        // for(int i = 0; i < size_comp.size(); i++) {
        //     res += 1LL * size_comp[i] * (remaining - size_comp[i]);
        //     remaining -= size_comp[i];
        // }
        // return res;
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);
        for(auto&V:edges){
            int u=V[0];
            int v=V[1];
            if(find(u)!=find(v)) Union(u,v);
        }
        
        unordered_map<int,int> size_comp;
        for(int i=0;i<n;i++){
            size_comp[find(i)]++;
        } 
        long long remaining=n;
        long long res=0;
        for(int i=0;i<size_comp.size();i++){
            int size=size_comp[i];
            res+=1LL*size*(remaining-size);
            remaining=remaining-size;
        }
        return res;
    }
};
