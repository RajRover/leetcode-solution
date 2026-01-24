class Solution {
public:
    bool contains(const vector<int>& have, const vector<int>& need){
        for(int i = 0; i < 128; i++){
            if(have[i] < need[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int low = 0;
        int n = s.size();
        int res = n + 1;
        int start = 0;

        vector<int> have(128, 0);
        vector<int> need(128, 0);

        for(char ch : t)
            need[(unsigned char)ch]++;

        for(int high = 0; high < n; high++){
            have[(unsigned char)s[high]]++;

            while(contains(have, need)){
                int len = high - low + 1;
                if(res > len){
                    res = len;
                    start = low;
                }
                have[(unsigned char)s[low]]--;
                low++;
            }
        }

        return res > n ? "" : s.substr(start, res);
    }
};

