class Solution {
public:
    void fn(int n,string &digits,unordered_map<char,string> alpha,int idx,vector<string> &ans,string diary){
        //base
        if(idx==n){
            ans.push_back(diary);
            return;
        }
        //make choices
        string choice=alpha[digits[idx]];
        for(int i=0;i<choice.size();i++){
            diary.push_back(choice[i]);
            fn(n,digits,alpha,idx+1,ans,diary);
            diary.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> alpha;
        alpha['2']="abc";
        alpha['3']="def";
        alpha['4']="ghi";
        alpha['5']="jkl";
        alpha['6']="mno";
        alpha['7']="pqrs";
        alpha['8']="tuv";
        alpha['9']="wxyz";
        
        vector<string> ans;
        fn(digits.size(),digits,alpha,0,ans,"");
        return ans;

    }
};
