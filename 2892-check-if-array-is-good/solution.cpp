class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        // Good array must have size = mx + 1
        if (n != mx + 1) return false;

        vector<int> freq(mx + 1, 0);

        for (int x : nums) {
            if (x < 1 || x > mx) return false;
            freq[x]++;
        }

        // 1 to mx-1 must appear once
        for (int i = 1; i < mx; i++) {
            if (freq[i] != 1) return false;
        }

        // mx must appear twice
        return freq[mx] == 2;
    }
};
