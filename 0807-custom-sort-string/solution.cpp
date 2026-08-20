class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> alpha(26,0);
        for(char ch:s){
            alpha[ch-'a']++;
        }
        string ans="";
        for(char ch:order){
            while(alpha[ch-'a']>0){
                ans+=ch;
                alpha[ch-'a']--;
                
            }
        }
        for(int i=0;i<26;i++){
            while(alpha[i]>0){
                ans+=string(1,i+'a');
                alpha[i]--;
            }
        }    
        return ans;
        
    }
};
