class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0;
        for(char ch:s){
            if(ch==letter) cnt++;
        }
        return 100*cnt/s.size();
    }
};
