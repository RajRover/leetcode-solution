class Solution {
public:
    bool valid(int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>= m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        int time=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,-1,1};
        while(!q.empty() && fresh>0){
            time++;
            int s=q.size();
            while(s--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int row=r+x[k];
                    int col=c+y[k];
                    if(valid(row,col,n,m) && grid[row][col]==1){
                        q.push({row,col});
                        fresh--;
                        grid[row][col]=2;
                    }
                }
            }
        }
        if(fresh>0) return -1;
        return time;
    }
};
