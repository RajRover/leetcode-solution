class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj,
        int u,
        vector<int>& path) {
//         Why while + pop_back()?
// Because we must remove each edge exactly once.
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();   // consume edge

            dfs(adj, v, path);
        }

        path.push_back(u);   // after all edges used
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //heriholzer algo
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indegree,outdegree;
        for(auto&it:pairs){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int n=adj.size();
        //find start node
        //start = out-in=1
        int start=pairs[0][0];
        //ignore values by putting '_'
        for(auto&[node,_]:adj){
            if(outdegree[node]-indegree[node]==1){
            start=node; 
            break;}
        }
        //now dfs on start node
        vector<int> path;
        dfs(adj,start,path);
        reverse(path.begin(),path.end());
        vector<vector<int>> res;
        for(int i=0;i<path.size()-1;i++){
            res.push_back({path[i],path[i+1]});
        }
        return res;
    }
};
