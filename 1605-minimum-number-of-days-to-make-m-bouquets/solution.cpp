class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0, bouquets = 0;
        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }
        bouquets += cnt / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;
        if (total > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;   // move left
            } else {
                low = mid + 1;    // move right
            }
        }
        return ans;
    }
};

