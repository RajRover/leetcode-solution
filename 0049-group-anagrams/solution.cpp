class Solution {
public:
    void generate(string &word){
        vector<int>alpha(26,0);
        for(char ch:word){
            alpha[ch-'a']++;
        }
        word="";
        for(int i=0;i<26;i++){
            if(alpha[i]>0){
                word+=string(alpha[i],i+'a');
            }
        }
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string,vector<string>> mp;
        // for(int i=0;i<strs.size();i++){
        // string s=strs[i];
        // sort(s.begin(),s.end());
        //     mp[s].push_back(strs[i]);
        // }
        // vector<vector<string>> res;
        // for(auto it:mp){
        //     res.push_back(it.second);
        // }
        // return res;

        int n=strs.size();
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string word=strs[i];
            generate(word);
            mp[word].push_back(strs[i]);
        }
        int k=mp.size();
        vector<vector<string>> res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};
