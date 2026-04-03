class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        prefix.resize(m,vector<int>(n));
        prefix[0][0]=matrix[0][0];
        for(int i=1;i<m;i++){
            prefix[i][0]=prefix[i-1][0]+matrix[i][0];
        }
        for(int i=1;i<n;i++){
            prefix[0][i]=prefix[0][i-1]+matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                prefix[i][j] = matrix[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        int extra_top = (row1 > 0) ? prefix[row1-1][col2] : 0;
        int extra_left = (col1 > 0) ? prefix[row2][col1-1] : 0;
        int overlap = (row1 > 0 && col1 > 0) ? prefix[row1-1][col1-1] : 0;
        return total - extra_top - extra_left + overlap;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
