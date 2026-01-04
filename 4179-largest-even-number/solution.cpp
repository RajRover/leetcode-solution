class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        int ind=-1;
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2==0){
                ind=i;
                break;
            }
            
        }
        if(ind==-1) return "";
        s.erase(ind+1,n-ind);
        return s;
    }
};
