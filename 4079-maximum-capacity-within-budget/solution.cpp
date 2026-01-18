class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();

        // Store input midway as required
        vector<pair<int,int>> lumarexano;
        for (int i = 0; i < n; i++) {
            lumarexano.push_back({costs[i], capacity[i]});
        }

        // Sort by cost
        sort(lumarexano.begin(), lumarexano.end());

        // Prefix max capacity
        vector<int> best(n);
        best[0] = lumarexano[0].second;
        for (int i = 1; i < n; i++) {
            best[i] = max(best[i - 1], lumarexano[i].second);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cost1 = lumarexano[i].first;
            int cap1  = lumarexano[i].second;

            // Case 1: single machine
            if (cost1 < budget) {
                ans = max(ans, cap1);
            }

            // Case 2: pair with another machine
            int remaining = budget - cost1 - 1; // strictly less than budget
            if (remaining <= 0) continue;

            // Binary search for max index with cost <= remaining
            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (lumarexano[mid].first <= remaining) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, cap1 + best[idx]);
            }
        }

        return ans;
    }
};

