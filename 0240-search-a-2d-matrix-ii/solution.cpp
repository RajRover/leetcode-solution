class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int row=n-1;
        int m=matrix[0].size();
        int col=0;
        while(row>=0 && col<=m-1){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target){
                //neglect col
                col++;
            }
            else{
                //neglect row
                row--;
            }
        }
        return false;
    }
};
