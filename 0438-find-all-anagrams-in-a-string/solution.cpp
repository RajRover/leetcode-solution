class Solution {
public:
    bool contains(vector<int>& have, vector<int>& need) {
        for (int i = 0; i < 26; i++) {
            if (have[i] < need[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        vector<int> have(26, 0);
        vector<int> need(26, 0);

        // Populate frequency arrays
        for (char ch : p) {
            need[ch - 'a']++;
        }
        vector<int>ans;
        for (int i = 0; i < p.size(); i++) {
            have[s[i] - 'a']++;
        }
        int low = 0;
        // Slide the window across s
        for (int i = p.size(); i < s.size(); ++i) {
            if (contains(need, have)) ans.push_back(low);

            // Add the new character entering the window
            have[s[i] - 'a']++;
            
            // Remove the character leaving the window
            have[s[low] - 'a']--;
            low++;
        }
        if(contains(need, have)) ans.push_back(low);
        return ans;
    }
};
