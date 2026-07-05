class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> need;
        for(string c:words){
            need[c]++;
        }
        int n = s.size();
        int word_len = words[0].size();
        int num_words = words.size();
        int total_len = word_len * num_words;
        vector<int>ans;
        // You only need to check offsets from 0 to k-1
        for (int offset = 0; offset < word_len; offset++) {
            int low = offset;
            int high = offset;
            unordered_map<string, int> have;
            
            while (high + word_len <= n) {
                // Add word to window
                string w = s.substr(high, word_len);
                have[w]++;
                high += word_len;
                
                // Remove word if window is too big
                if (high - low > total_len) {
                    string left_w = s.substr(low, word_len);
                    have[left_w]--;
                    if (have[left_w] == 0) have.erase(left_w);
                    low += word_len;
                }
                
                // Check match
                if (have == need) {
                    ans.push_back(low);
                }
            }
        }
        return ans;
    }
};
