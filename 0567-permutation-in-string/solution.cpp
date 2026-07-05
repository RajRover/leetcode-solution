class Solution {
public:
    bool contains(vector<int>& have, vector<int>& need) {
        for (int i = 0; i < 26; i++) {
            if (have[i] < need[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> have(26, 0);
        vector<int> need(26, 0);

        // Populate frequency arrays
        for (char ch : s1) {
            need[ch - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            have[s2[i] - 'a']++;
        }

        int low = 0;
        // Slide the window across s2
        for (int i = s1.size(); i < s2.size(); ++i) {
            if (contains(need, have)) return true;

            // Add the new character entering the window
            have[s2[i] - 'a']++;
            
            // Remove the character leaving the window
            have[s2[low] - 'a']--;
            low++;
        }

        // Check the very last window
        return contains(need, have);
    }
};
