class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<char>> Rotated(m, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Rotated[j][n - 1 - i] = boxGrid[i][j];
            }
        }
        for(int col=0;col<n;col++){
            int empty=m-1;
            for(int row=m-1;row>=0;row--){
                if(Rotated[row][col]=='*'){
                    empty=row-1;
                }
                else if(Rotated[row][col]=='#'){
                    swap(Rotated[row][col],Rotated[empty][col]);
                    empty--;
                }
            }
        }
        return Rotated;
        
    }
};
