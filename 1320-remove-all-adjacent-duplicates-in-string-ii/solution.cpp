class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(st.empty()) {st.push({s[i],1});
            continue;}
            if(st.top().first!=s[i]){
                st.push({s[i],1});
                continue;
            }
            if(st.top().second<k-1){
                st.top().second++;
                continue;
            }
            st.pop();
        }
        while(!st.empty()){
            pair<char,int> p=st.top();
            while(p.second--){
                res.push_back(st.top().first);
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
