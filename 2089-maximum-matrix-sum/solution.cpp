class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;           // total sum
        int negCount = 0;            // count of negative numbers
        int smallest = INT_MAX;      // smallest absolute value

        // Loop through the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (val < 0) negCount++;
                sum += llabs(val);           // add absolute value
                smallest = min(smallest, abs(val)); // track smallest abs
            }
        }

        // If odd number of negatives, subtract twice the smallest absolute value
        if (negCount % 2 == 1) {
            sum -= 2LL * smallest;
        }

        return sum;
    }
};

