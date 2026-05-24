class Solution {
public:
    int passwordStrength(string password) {
        int cnt=0;
        set<int>st;
        for(char ch:password){
            st.insert(ch);
        }
        for(char ch:st){
            if(ch-'a'>=0 && ch-'z'<=0){
                cnt++;
            }
            else if(ch-'A'>=0 && ch-'Z'<=0){
                cnt+=2;
            }
            else if(ch-'0'>=0 && ch-'9'<=0){
                cnt+=3;
            }
            else if(ch=='!' || ch=='@' || ch=='#' || ch=='$'){
                cnt+=5;
            }
        }
        return cnt;
    }
};
