class Solution {
public:
    bool parity(char ch){
        if((ch-'0')%2) return true;
        return false;
    }
    string getSmallestString(string s) {
        int low=0;
        int high=1;
        int n=s.size();
        while(high<n){
            if(((s[low]-s[high])>0) && (parity(s[low])==parity(s[high]))){
                swap(s[low],s[high]);
                return s;
            }
            low++;
            high++;
        }
        return s;
    }
};
