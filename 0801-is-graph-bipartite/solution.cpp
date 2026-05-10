class Solution {
public:
    // bool dfs(vector<vector<int>>& graph,vector<int>&color,int curr_node,int curr_color){
    //     color[curr_node]=curr_color;
    //     for(int &v:graph[curr_node]){
    //         if(color[v]==color[curr_node]) return false;
    //         if(color[v]==-1){
    //             color[v]=1-color[curr_node];
    //             if(!dfs(graph,color,v,color[v])) return false;
    //         }

    //     }
    //     return true;
    // }
    bool BFS(vector<vector<int>>& graph,vector<int>&color,int curr_node,int curr_color){
        queue<int> q;
        q.push(curr_node);
        color[curr_node]=curr_color;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int&v:graph[u]){
                if(color[v]==color[u]) return false;
                if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
            return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        // for(int i=0;i<v;i++){
        //     if(color[i]==-1){
        //         if(!dfs(graph,color,i,0)) return false;
        //     }
        // }
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(!BFS(graph,color,i,0)) return false;
            }
        }
        return true;
    }
};
