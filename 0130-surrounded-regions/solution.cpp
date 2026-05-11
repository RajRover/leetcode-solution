class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();

        // boundary + only visit O
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O')
            return;

        board[x][y] = '#';

        vector<int> dir = {-1, 0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int x_new = x + dir[k];
            int y_new = y + dir[k + 1];
            dfs(board, x_new, y_new);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int top=0;
        int left=0;
        int bottom=m-1;
        int right=n-1;
        // left + right columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // top + bottom rows
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

         // flip remaining O, restore #
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
