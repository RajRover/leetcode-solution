class Solution {
public:
    void fn(int n,int open,int close,string diary,vector<string> &res){
        //base case
        if(open==n && close==n){
            res.push_back(diary);
            return;
        }
        //make choice
        //open
        if(open<n){
            diary.push_back('(');
            fn(n,open+1,close,diary,res);
            diary.pop_back();
        }
        //close
        if(close<open){
            diary.push_back(')');
            fn(n,open,close+1,diary,res);
            diary.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        fn(n,0,0,"",res);
        return res;
    }
};
