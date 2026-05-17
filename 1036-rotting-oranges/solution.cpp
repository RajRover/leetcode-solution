class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        int min=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                for(auto&v:directions){
                    int a_new=a+v[0];
                    int b_new=b+v[1];
                    if(a_new>=0 && a_new<n && b_new>=0 && b_new<m && grid[a_new][b_new]==1){
                        grid[a_new][b_new]=2;
                        q.push({a_new,b_new});
                        fresh--;
                    }
                    else continue;
                }
            }
            min++;
        }
        if(min==0 && fresh==0) return 0;
        return (fresh==0)?min-1:-1;
    }
};
