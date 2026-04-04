class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        stack<char> st;

        for (char c : s) {
            freq[c - 'a']--;

            // skip if already in stack
            if (visited[c - 'a']) continue;

            // maintain lexicographical order
            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        // build answer
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
