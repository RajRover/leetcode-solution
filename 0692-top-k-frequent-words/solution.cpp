class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first; // Min-heap based on frequency
            }
            return a.second < b.second;   // If frequency is equal, max-heap based on lexicographical order
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }

        // Min-heap to store the top k elements
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop(); // Remove the least frequent / highest lexicographical element
            }
        }

        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};
