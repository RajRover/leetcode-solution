class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.size();
        int i=0;
        while(i<n-1){
            if((abs(s[i+1]-s[i]))>2) return false;
            i++;
        }
        return true;
    }
};
