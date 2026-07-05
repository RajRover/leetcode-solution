class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int res=0;
        unordered_map<char,int> freq;
        for(int high=0;high<s.size();high++){
            freq[s[high]]++;
            //jabtak galat
            int k=high-low+1;
            while(freq.size()<k){
                freq[s[low]]--;
                if(freq[s[low]]==0) freq.erase(s[low]);
                low++;
                k=high-low+1;
            }
            if(freq.size()==k){
                int len=high-low+1;
                res=max(len,res);
            }
        }
        return res;
    }
};
