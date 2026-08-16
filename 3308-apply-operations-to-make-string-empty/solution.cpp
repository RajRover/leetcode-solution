class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> freq;
        int max_cnt=0;
        for(char ch:s){
            freq[ch]++;
            max_cnt=max(max_cnt,freq[ch]);
        }
        vector<int>cur_count(26,0);
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            cur_count[ch-'a']++;
            if(freq[ch]==max_cnt && cur_count[ch-'a']==1) ans+=ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
