class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0;
        int res=0;
        unordered_map<char,int>f;
        int max_cnt=0;
        for(int high=0;high<s.size();high++){
            f[s[high]]++;
            max_cnt=max(max_cnt, f[s[high]]);
            int len=high-low+1;
            int diff=len-max_cnt;
            while(diff>k){
                f[s[low]]--;
                if(f[s[low]]==0) f.erase(s[low]);
                low++;
                len=high-low+1;
                diff=len-max_cnt;
            }
            //len=high-low+1;
            res=max(len,res);
        }
        return res;
    }
};
