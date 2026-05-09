class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    int layers = min(m, n) / 2;

    for(int l = 0; l < layers; l++) {
        int top = l;
        int bottom = m - l - 1;
        int left = l;
        int right = n - l - 1;

        vector<int> store;

        // 1. top row
        for(int j = left; j <= right; j++)
            store.push_back(grid[top][j]);

        // 2. right column
        for(int i = top + 1; i <= bottom; i++)
            store.push_back(grid[i][right]);

        // 3. bottom row
        for(int j = right - 1; j >= left; j--)
            store.push_back(grid[bottom][j]);

        // 4. left column
        for(int i = bottom - 1; i > top; i--)
            store.push_back(grid[i][left]);

        // rotate store
        int len = store.size();
        int shift = k % len;
        rotate(store.begin(), store.begin() + shift, store.end());

        // put back (same traversal)
        int idx = 0;

        for(int j = left; j <= right; j++)
            grid[top][j] = store[idx++];

        for(int i = top + 1; i <= bottom; i++)
            grid[i][right] = store[idx++];

        for(int j = right - 1; j >= left; j--)
            grid[bottom][j] = store[idx++];

        for(int i = bottom - 1; i > top; i--)
            grid[i][left] = store[idx++];
    }

    return grid;
    }
};
