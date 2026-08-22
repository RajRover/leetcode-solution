class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> req(n);
        
        for (int i = 0; i < n; i++) {
            req[i] = capacity[i] - rocks[i];
        }
        
        sort(req.begin(), req.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (additionalRocks >= req[i]) {
                additionalRocks -= req[i];
                count++;
            } else {
                break;
            }
        }
        return count;
        
    }
};
