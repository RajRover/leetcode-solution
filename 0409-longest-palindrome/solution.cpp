class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> f;
        for(char ch:s){
            f[ch]++;
        }
        bool odd=false;
        int cnt=0;
        for(auto i:f){
            char c=i.first;
            int freq=i.second;
            if(freq%2==0 ){
                cnt+=freq;
            }
            else{
                cnt+=freq-1;
                odd=true;
            }
        }
        if(odd==true) return cnt+1;
        else return cnt;
    }
};
