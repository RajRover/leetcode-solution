class Solution {
public:
    vector<vector<int>> dp;

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(s1, s2, 0, 0);
    }

    int solve(string &s1, string &s2, int i, int j) {
        // If s1 is exhausted, delete remaining chars of s2
        if (i == s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++)
                sum += s2[k];
            return sum;
        }

        // If s2 is exhausted, delete remaining chars of s1
        if (j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++)
                sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, no deletion needed
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        // Delete from s1 or s2
        int delete1 = s1[i] + solve(s1, s2, i + 1, j);
        int delete2 = s2[j] + solve(s1, s2, i, j + 1);

        return dp[i][j] = min(delete1, delete2);
    }
};

