class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int windowStart = 0;
        long long distinctSum = 0;
        int minimumLength = INT_MAX;

        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            if(freq[nums[windowEnd]] == 0) {
                distinctSum += nums[windowEnd];
            }
            freq[nums[windowEnd]]++;

            while(distinctSum >= k) {
                minimumLength = min(minimumLength, windowEnd - windowStart + 1);
                freq[nums[windowStart]]--;
                if(freq[nums[windowStart]] == 0) {
                    distinctSum -= nums[windowStart];
                }
                windowStart++;
            }
        }

        return (minimumLength == INT_MAX) ? -1 : minimumLength;
    }
};

