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

    vector<vector<int>> matrix_exp(vector<vector<int>>& base, int exp) {
        if (exp == 0)
            return identity(base.size());

        vector<vector<int>> half = matrix_exp(base, exp / 2);
        vector<vector<int>> res = mat_mul(half, half);

        if (exp % 2)
            res = mat_mul(res, base);

        return res;
    }

    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // [T2, T1, T0]^T = [1,1,0]
        vector<vector<int>> base = {
            {1},
            {1},
            {0}
        };

        // Transition matrix
        vector<vector<int>> T = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0}
        };

        vector<vector<int>> res = matrix_exp(T, n - 2);

        res = mat_mul(res, base);

        return res[0][0];
    }
};
