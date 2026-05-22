class Solution {
public:
    void balance(multiset<int>& left, multiset<int>& right) {
        // keep left.size() >= right.size()
        while (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }

        while (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left;   // smaller half
        multiset<int> right;  // larger half
        vector<double> ans;

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            // Insert
            if (left.empty() || nums[j] <= *left.rbegin())
                left.insert(nums[j]);
            else
                right.insert(nums[j]);

            balance(left, right);

            // Window reached size k
            if (j - i + 1 == k) {

                // Compute median
                if (k % 2)
                    ans.push_back((double)*left.rbegin());
                else
                    ans.push_back(((double)*left.rbegin() + *right.begin()) / 2.0);

                // Remove nums[i]
                if (left.find(nums[i]) != left.end())
                    left.erase(left.find(nums[i]));
                else
                    right.erase(right.find(nums[i]));

                balance(left, right);
                i++;
            }
        }

        return ans;
    }
};
