class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //unordered_map<int,int>freq;
        int S_actual=0;
        int diff=0;
        int SS_actual=0;
        int sq_diff=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                S_actual+=grid[i][j];
                SS_actual+=1LL*grid[i][j]*grid[i][j];
                //freq[grid[i][j]]++;
            } 
        }
        diff=(1LL*n*n*(n*n+1)/2)-S_actual;
        sq_diff=(1LL*n*n*(n*n+1)*(2LL*n*n+1)/6)-SS_actual;
        int sum=sq_diff/diff;
        return {(sum-diff)/2,(sum+diff)/2};
    }
};
