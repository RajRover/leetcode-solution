class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;i++){
            int ans=1;
            vector<int> put;
            put.push_back(ans);
            for(int j=1;j<i;j++){
                ans=ans*(i-j);
                ans=ans/j;
                put.push_back(ans);
            }
            result.push_back(put);
        }
        return result;
    }
};
