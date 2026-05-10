class Solution {
public:
    // vector<int> bfs(unordered_map<int,vector<int>> &adj,vector<int> &inDegree,vector<bool> vis,int numCourses){
    //     queue<int> q;
    //     vector<int> res;
    //     for(int i=0;i<numCourses;i++){
    //             if(inDegree[i]==0){
    //                 q.push(i);
    //                 vis[i]=true;
    //                 res.push_back(i);
    //             }
                
    //     }
    //     while(!q.empty()){
    //         int u=q.front();
    //         q.pop();
    //         for(int &v:adj[u]){
    //             inDegree[v]--;
    //             if(!vis[v] &&inDegree[v]==0){
    //                 q.push(v);
    //                 vis[v]=true;
    //                 res.push_back(v);
    //             }
    //         }
    //     }
    //     return res;
    // }
    bool dfs(unordered_map<int,vector<int>> &adj,vector<bool>&inRecursion,vector<bool> &vis,stack<int>&st,int u){
        vis[u]=true;
        inRecursion[u]=true;
        for(int &v:adj[u]){
            if(!vis[v] && dfs(adj,inRecursion,vis,st,v)){
                return true;
            }
            else if(inRecursion[v]==true) return true;
        }
        inRecursion[u] = false;
        st.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto &i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
        // vector<int> inDegree(numCourses);
        // for(int i=0;i<numCourses;i++){
        //     for(int &v:adj[i]){
        //         inDegree[v]++;
        //     }
        // }
        vector<bool> vis(numCourses,false);
        //vector<int> ans=bfs(adj,inDegree,vis,numCourses);
        vector<bool> inRecursion(numCourses,false);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,inRecursion, vis, st, i)) return {};
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;

    }
};
