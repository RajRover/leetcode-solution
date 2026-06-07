class Solution {
public:
    vector<vector<string>> res;
    vector<vector<bool>>dp;
    void solve(int i,string s,vector<string>part){
        if(i==s.size()){
            res.push_back(part);
        }
        for(int j=i;j<s.size();j++){
            if(dp[i][j]){
                part.push_back(s.substr(i,j-i+1));
                solve(j+1,s,part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        dp.resize(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    if(L==2){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }
        vector<string>part;
        solve(0,s,part);
        return res;


    }
};
