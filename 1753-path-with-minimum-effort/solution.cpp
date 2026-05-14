class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> dir{
        {0,1},{1,0},{0,-1},
        {-1,0}
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<n && y>=0 && y<m;
        };
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if (d > dist[x][y]) continue;
            if (x == n - 1 && y == m - 1) return d;
            for(auto&v:dir){
                int x_=x+v[0];
                int y_=y+v[1];
                if(isSafe(x_,y_)){
                    int diff=max(abs(heights[x_][y_]-heights[x][y]),d);
                    if(dist[x_][y_]>diff){
                        dist[x_][y_]=diff;
                        pq.push({diff,{x_,y_}});
                    }
                }   
            }
        }
        return 0;
    }
};
