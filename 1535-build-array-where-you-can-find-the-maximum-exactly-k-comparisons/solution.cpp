class Solution {
public:

    int mod = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int solve(int idx, int mx, int sc, int n, int m, int k) {
        if(sc > k) return 0;
        if (idx == n) {
            return (sc == k);
        }

        long long res = 0;
        if(dp[idx][mx][sc]!=-1) return dp[idx][mx][sc];
        for (int i = 1; i <= m; i++) {

            if (i > mx) {
                res = (res + solve(idx + 1, i, sc + 1, n, m, k)) % mod;
            }
            else {
                res = (res + solve(idx + 1, mx, sc, n, m, k)) % mod;
            }
        }

        return dp[idx][mx][sc]=res;
    }

    int numOfArrays(int n, int m, int k) {
         dp = vector<vector<vector<int>>>(
            n + 1,
            vector<vector<int>>(
                m + 1,
                vector<int>(k + 1, -1)
            )
        );
        return solve(0, 0, 0, n, m, k);
    }
};
