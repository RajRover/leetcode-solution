class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> alphabets(26,0);
        int n=s.size();
        int low=0;
        int res=0;
        for(int high=0;high<n;high++){
            alphabets[s[high]-'A']+=1;
            int len =high-low+1;
            int maxcnt=*max_element(alphabets.begin(),alphabets.end());
            int diff=len-maxcnt;
            while(diff>k){
                alphabets[s[low]-'A']-=1;
                low++;
                len =high-low+1;
                maxcnt=*max_element(alphabets.begin(),alphabets.end());
                diff=len-maxcnt;
            }
            len =high-low+1;
            res=max(res,len);
        }
        return res;
    }
};
