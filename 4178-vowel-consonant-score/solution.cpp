class Solution {
public:
    bool isvowel(char ch){
        string str="aeiou";
        return (str.find(ch)!=string::npos);
    }
    bool isconsonent(char ch){
        string str="bcdfghjklmnpqrstvwxyz";
        return (str.find(ch)!=string::npos);
    }
    int vowelConsonantScore(string s) {
        int c=0;
        int v=0;
        for(char a:s){
            if(isvowel(a)){
                v++;
            }
            else if(isconsonent(a)){
                c++;
            }
        }
        if(c>0){
        return floor(v/c);}
        return 0;
    }
};
