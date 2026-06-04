class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int max_len=1;
        int idx=-1;
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j){
                    dp[i][j]=true;
                    idx=i;
                }
                else if(i+1==j && s[i]==s[j]){
                    dp[i][j]=true;
                    max_len=2;
                    idx=i;
                }
                else if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=true;
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        idx=i;
                    }
                }
            }
        }
        return s.substr(idx,max_len);
    }
};
