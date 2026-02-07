class Solution {
public:
    int fn(vector<vector<int>>& matrix,int guess){
        int n=matrix.size();
        int m=matrix[0].size();
        int row=n-1;
        int col=0;
        int cnt=0;
        while(row>=0 && col<m){
            if(matrix[row][col]>guess){
                row--;
            }
            else{
                cnt+=row+1;
                col=col+1;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        int ans=-1;
        while(low<=high){
            int guess=low+(high-low)/2;
            int res=fn(matrix,guess);
            if(res<k){
                //right
                low=guess+1;
            }
            else{
                //possible
                ans=guess;
                high=guess-1;
            }
        }
        return ans;
    }
};
