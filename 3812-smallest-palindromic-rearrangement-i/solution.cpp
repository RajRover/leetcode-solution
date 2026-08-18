class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1 || n==0) return s;
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        string left="";
        string middle="";
        for(int i=0;i<26;i++){
            left+=string(freq[i]/2,'a'+i);
            if(freq[i]%2==1){
                middle+='a'+i;
            }
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};
