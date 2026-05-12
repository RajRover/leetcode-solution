class Solution {
public:
    int dfs(vector<vector<int>>& grid,int x,int y){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y]=0;
        int area=1;
        vector<int> dir={-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int x_new=x+dir[i];
            int y_new=y+dir[i+1];
            area+=dfs(grid,x_new,y_new);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    res=max(res,dfs(grid,i,j));
                }
            }
        }
        return res;
    }
};
