class Solution {
public:
    // vector<int> dp;
    // int solve(int idx,string &s){
    //     if(idx==s.size()) return 1;
    //     if(s[idx]=='0') return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     int ways=0;
    //     //take one step
    //     ways+=solve(idx+1,s);
    //     //take two step
    //      if(idx + 1 < s.size()){
    //         int num=(s[idx]-'0')*10+(s[idx+1]-'0');
    //         if(num>=10 && num<=26){
    //             ways+=solve(idx+2,s);
    //         }
    //     }
        
    //     return dp[idx]=ways;
        
    // }
    int numDecodings(string s) {
        // dp.resize(s.size(),-1);
        // return solve(0,s);
        vector<int>dp(s.size()+1);
        if(s[0]!='0'){
            dp[0]=1;
        }
        else return 0;
        for(int i=1;i<=s.size();i++){
            // one digit
            if(s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if(i>=2){
                int num=(s[i-2]-'0')*10+(s[i-1]-'0');
                if(num<=26 && num>=10){
                     dp[i]+=dp[i-2];
                }
            }
           
        }
        return dp[s.size()];
    }
};
