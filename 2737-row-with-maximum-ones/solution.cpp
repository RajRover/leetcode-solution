class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cntmax = 0;
        int index = 0;

        for (int i = 0; i < mat.size(); i++) {
            int cntones = count(mat[i].begin(), mat[i].end(), 1);
            if (cntones > cntmax) {
                cntmax = cntones;
                index = i;
            }
        }

        return {index, cntmax};
    }
};

