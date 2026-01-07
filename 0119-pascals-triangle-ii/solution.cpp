class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        long long ans=1;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            ans=ans*(rowIndex+1-i);
            ans=ans/i;
            result.push_back(ans);
        }
        return result;
    }
};
