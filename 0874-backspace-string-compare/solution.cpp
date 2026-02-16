class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m=s.size();
        int n=t.size();
        int i=m-1;
        int j=n-1;
        int skipS=0;
        int skipT=0;
        while(i>=0 || j>=0){
            //first valid char
            while(i>=0){
                if(s[i]=='#'){
                    skipS++;
                    i--;
                }
                else if(skipS>0){
                    skipS--;
                    i--;
                }
                else break;
            }
            while(j>=0){
                if(t[j]=='#'){
                    skipT++;
                    j--;
                }
                else if(skipT>0){
                    skipT--;
                    j--;
                }
                else break;
            }
            if(i>=0 && j>=0) 
                {if(s[i]!=t[j])
                    return false;
                }
            else{
                if(i>=0 || j>=0){
                    return false;
                }
            }
        i--;
        j--;
        } 
    return true;      
    } 
};
        // stack<char> st1;
        // for(char ch:s){
        //     if(ch=='#' && !st1.empty()) st1.pop();
        //     else{
        //      st1.push(ch);   
        //     }
        // }
        // stack<char> st2;
        // for(char ch:t){
        //     if(ch=='#' && !st2.empty()) st2.pop();
        //     else{
        //      st2.push(ch);   
        //     }
        // }
        // if(st1.size()!=st2.size()) return false;
        // while(!st1.empty() && !st1.empty()){
        //     if(st1.top()==st2.top()){
        //         st1.pop();
        //         st2.pop();
        //         continue;
        //     }
        //     else return false;;
        // }
        // return true;
