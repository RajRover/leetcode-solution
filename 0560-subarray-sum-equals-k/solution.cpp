class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int cnt = 0;
        unordered_map<long long, int> premap;
        premap[0] = 1;

        for (int num : nums) {
            sum += num;
            if (premap.find(sum - k) != premap.end()) {
                cnt += premap[sum - k];
            }
            premap[sum]++;
        }
        return cnt;
    }
};

