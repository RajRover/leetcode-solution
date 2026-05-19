class Solution {
public:
    //dfs
    vector<vector<int>> ans;
    // void dfs(vector<vector<int>>& graph,int u,vector<int>&path){
    //     path.push_back(u);
    //     if(u == graph.size() - 1) ans.push_back(path);
    //     else{
    //         for(int&v:graph[u]){
    //             dfs(graph,v,path);
    //         }
    //     }
    //     path.pop_back();
    // }
    //BFS
    void bfs(vector<vector<int>>& graph){
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            vector<int>path=q.front();
            q.pop();
            int node=path.back();
            if(node==graph.size() - 1){
                ans.push_back(path);
                continue;
            }
            for(auto&v:graph[node]){
                vector<int>new_path=path;
                new_path.push_back(v);
                q.push(new_path);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //dfs
        //vector<int>path;
        //dfs(graph,0,path);
        bfs(graph);
        return ans;
    }
};
