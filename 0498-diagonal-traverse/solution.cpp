class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>> mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               mp[i+j].push_back(mat[i][j]);}
        }
        for(auto &it:mp){
            if(it.first%2==0){
                reverse(it.second.begin(),it.second.end());
            }
            
        }
        vector<int>res;
        for(int sum=0;sum<m+n-1;sum++){
            for (int num : mp[sum]) {
                res.push_back(num);
            }
        }
        return res;
    }
};
