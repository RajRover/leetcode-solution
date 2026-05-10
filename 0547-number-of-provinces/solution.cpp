class Solution {
public:
    // bool dfs(vector<vector<int>>& isConnected,vector<bool> &vis,int u){
    //     int n=isConnected.size();
    //     vis[u]=true;
    //     for(int i=0;i<n;i++){
    //         if(isConnected[u][i]==1 && u!=i && !vis[i]){
    //             dfs(isConnected,vis,i);
    //         }
    //     }
    //     return true;
    // }
    bool bfs(vector<vector<int>>& isConnected,vector<bool> &vis,int u){
        queue<int> q;
        int n=isConnected.size();
        q.push(u);
        vis[u]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v=0;v<n;v++){
                if(isConnected[u][v]==1 && u!=v && !vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
        return false;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        // unordered_map<int,vector<int>> adj(n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i!=j && isConnected[i][j]){
        //              adj[i].push_back(j);
        //              adj[j].push_back(i);
        //         }
                
        //     }
        // }
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(isConnected,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};
