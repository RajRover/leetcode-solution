class Solution {
public:
    vector<vector<int>> identity(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            res[i][i] = 1;
        return res;
    }
    vector<vector<int>> mat_mul(vector<vector<int>>& A,
                                vector<vector<int>>& B) {
        int n = A.size();
        int m = B[0].size();
        int p = B.size();

        vector<vector<int>> C(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < p; k++) {
                    C[i][j] =
                        (C[i][j] + 1LL * A[i][k] * B[k][j]);
                }
            }
        }
        return C;
    }

    //dp+memoization
    // int solve(int n,vector<int>&dp){
    //     if(n<=2) return n;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }

    vector<vector<int>> matrix_exp(vector<vector<int>>& base, int exp) {
        if (exp == 0)
            return identity(base.size());

        vector<vector<int>> half = matrix_exp(base, exp / 2);
        vector<vector<int>> res = mat_mul(half, half);

        if (exp % 2)
            res = mat_mul(res, base);

        return res;
    }

    int climbStairs(int n) {
        ////memoization
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        //bottom up
        // if(n<=1) return n;
        // int a=1;
        // int b=2;
        // for(int i=3;i<=n;i++){
        //     int c=a+b;
        //     a=b;
        //     b=c;
        // }
        // return b;

        if(n<=1) return n;
        vector<vector<int>> base = {
            {1},
            {0}
        };
        vector<vector<int>> T = {
            {1, 1},
            {1, 0}
        };

        vector<vector<int>> res = matrix_exp(T, n);
        vector<vector<int>> ans = mat_mul(res, base);
        return ans[0][0];


    }
};
