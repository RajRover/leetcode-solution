class Solution {
public:
    bool predecssor(string&a,string&b){
        if (b.size() != a.size() + 1)
            return false;
        bool skipped=false;
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                if(skipped) return false;
                skipped=true;
                j++;
            }
        }
        return true;
    }
    // vector<vector<int>>dp;//TC=(n^2)L
    // int solve(int idx,int p,vector<string>& words){
    //     if(idx>=words.size()) return 0;
    //     if(dp[idx][p+1]!=-1) return dp[idx][p+1];
    //     int take=0;
    //     if(p==-1 || predecssor(words[p],words[idx])){
    //         take=1+solve(idx+1,idx,words);
    //     }
    //     int skip=solve(idx+1,p,words);
    //     return dp[idx][p+1]=max(skip,take);
    // }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),
            [](string&a,string&b){
                return b.size()>a.size();});
        //dp.resize(words.size(),vector<int>(words.size(),-1));
        //return solve(0,-1,words);
        int res=1;
        vector<int>dp(words.size(),1);
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(predecssor(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                    res=max(dp[i],res);
                }
            }
        }
        return res;
    }
};

