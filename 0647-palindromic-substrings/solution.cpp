class Solution {
public:
    // vector<vector<int>>dp;
    // bool check(int i,int j,string s){
    //     if(i>j) return true;
    //     if(s[i]==s[j]){
    //         return check(i+1,j-1,s);
    //     }
    //     return false;
        
    // }
    int countSubstrings(string s) {
        // int cnt=0;
        // for(int i=0;i<s.size();i++){
        //     for(int j=i;j<s.size();j++){
        //         if(check(i,j,s)){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        int n=s.size();
        int cnt=0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(i==j) //length 1
                {
                    dp[i][j]=true;
                }
                else if(j==i+1){
                    dp[i][j]=s[i]==s[j];
                }
                else{
                    dp[i][j]=dp[i+1][j-1] && s[i]==s[j];
                }
                if(dp[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
