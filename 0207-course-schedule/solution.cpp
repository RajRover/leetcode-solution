class Solution {
public:
    // bool BFS(unordered_map<int,vector<int>> &adj,vector<int> &inDegree,vector<bool> &vis,int numCourses){       //vector<int> res;
    //     queue<int> q;
    //     int cnt=0;
    //     for(int i=0;i<numCourses;i++){
    //         if(inDegree[i]==0){
    //             q.push(i);
    //             vis[i]=true;
    //             //res.push_back(i);
    //             cnt++;
    //         }
    //     }
    //     while(!q.empty()){
    //         int u=q.front();
    //         q.pop();
    //         for(int &v:adj[u]){
    //             inDegree[v]--;
    //             if(!vis[v] && inDegree[v]==0){
    //                 vis[v]=true;
    //                 q.push(v);
    //                 //res.push_back(v);
    //                 cnt++;
    //             }
    //         }
    //     }
    //     if(cnt==inDegree.size()) return true;
    //     return false;
    // }
    bool dfs_cycle(unordered_map<int,vector<int>> &adj,vector<bool> &vis,vector<bool>&inRecursion,int u){
        vis[u]=true;
        inRecursion[u]=true;
        for(int &v:adj[u]){
            if(!vis[v] && dfs_cycle(adj,vis,inRecursion,v)){
                return true;
            }
            else if(inRecursion[v]==true){
                return true;;
            }
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==1 || prerequisites.empty()) return true;
        unordered_map<int,vector<int>> adj(numCourses);
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];
            adj[v].push_back(u);
        }
        // vector<int> inDegree(numCourses);
        // for(int i=0;i<numCourses;i++){
        //     for(int &v:adj[i]){
        //         inDegree[v]++;
        //     }
        // }
         vector<bool> vis(numCourses,false);
        // return BFS(adj,inDegree,vis,numCourses);
        vector<bool> inRecursion(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs_cycle(adj,vis,inRecursion,i)) return false;
            }
        }
        return true;
    }
};
