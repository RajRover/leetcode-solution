class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> height(n, vector<int>(m));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1) {
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int level=1;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto&v:directions){
                    int i_=i+v[0];
                    int j_=j+v[1];
                    if(i_>=0 && i_<n && j_>=0 && j_<m && isWater[i_][j_]!=1){
                        q.push({i_,j_});
                        isWater[i_][j_]=1;
                        height[i_][j_]=level;
                    }
                }
            }
            level++;
        }
        return height;
    }
};
