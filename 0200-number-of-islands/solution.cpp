class Solution {
public:
    bool valid(int i,int j,int m, int n){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &vis,vector<vector<char>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,-1,1};
        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(valid(row,col,m,n) && grid[row][col]=='1' && vis[row][col]==0){
                dfs(vis,grid,row,col);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(vis,grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};
