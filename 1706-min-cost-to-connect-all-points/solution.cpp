// class Solution {
// public:
//    Prims
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int n=points.size();
//         vector<vector<pair<int,int>>> adj(n);
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 int dist=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
//                 adj[i].push_back({j,dist});
//                 adj[j].push_back({i,dist});
//             }
//         }
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<bool> vis(n,false);
//         pq.push({0,0});
//         int sum=0;
//         while(!pq.empty()){
//             int d=pq.top().first;
//             int node=pq.top().second;
//             pq.pop();
//             if(vis[node]) continue;
//             vis[node]=true;
//             sum+=d;
//             for(auto&v:adj[node]){
//                 int nbr=v.first;
//                 int dist=v.second;
//                 if(!vis[nbr]){
//                     pq.push({dist,nbr});
//                 }
//             }
//         }
//         return sum;

//     }
// };
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else {
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> vec;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                vec.push_back({i,j,dist});
            }
        }
        auto comparator=[&](vector<int>&vec1,vector<int>&vec2){
            return vec1[2]<vec2[2];
        };
        sort(vec.begin(),vec.end(),comparator);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);
        int sum=0;
        for(auto&v:vec){
            int u=v[0];
            int y=v[1];
            int d=v[2];
            if(find(u)!=find(y)){
                Union(u,y);
                sum+=d;
            }
        }
        return sum;

    }
};

