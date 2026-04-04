class Solution {
public:
//gready+stack
    string removeKdigits(string num, int k) {
        //remove prev greater
        string st="";
        for(char c:num){
            //remove bad choices
            while(!st.empty() && st.back()>c && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        //remove next greater(end) if k>0
        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }

        //remove zeros or spaces
        int i = 0;
        while(i < st.size() && st[i] == '0') i++;
        string ans=st.substr(i);
        return (ans=="")?"0":ans;
    }
};
