class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
    int m = a.size();
    int n = a[0].size();

    // Find the candidate row
    int low = 0, high = m - 1;
    int row = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid][0] <= target && target <= a[mid][n - 1]) {
            row = mid;
            break;
        }
        else if (a[mid][0] <= target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (row == -1)
        return false;

    // Binary search in the selected row
    low = 0;
    high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[row][mid] < target) {
            low = mid + 1;
        }
        else if (a[row][mid] > target) {
            high = mid - 1;
        }
        else {
            return true;
        }
    }

    return false;
    }
};
