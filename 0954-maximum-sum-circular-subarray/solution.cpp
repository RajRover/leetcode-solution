class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = nums[0];
        int max_best = nums[0], min_best = nums[0];
        int max_sum = nums[0], min_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            max_best = max(nums[i], nums[i] + max_best);
            max_sum = max(max_sum, max_best);

            min_best = min(nums[i], nums[i] + min_best);
            min_sum = min(min_sum, min_best);

            total += nums[i];
        }

        // all elements are negative
        if (max_sum < 0) return max_sum;

        return max(max_sum, total - min_sum);
    }
};

