class Solution {
public:
    bool pallindrome(string &s,int low,int high){
       //base case 
       int len=high-low+1;
       if(len==0 || len==1) return true;
       //take one rest trust
       if(s[low]!=s[high]) return false;
       return pallindrome(s,low+1,high-1);
    }
    void fn(string &s,int n,vector<string>diary,vector<vector<string>> &res,int idx){
        //base
        if(idx==n){
            res.push_back(diary);
            return;
        }
        //choices
        for(int i=idx;i<n;i++){
            if(pallindrome(s,idx,i)){
                diary.push_back(s.substr(idx, i - idx + 1));
                fn(s,n,diary,res,i+1);
                diary.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>diary;
        fn(s,s.size(),diary,res,0);
        return res;
    }
};
