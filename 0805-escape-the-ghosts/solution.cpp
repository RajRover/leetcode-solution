class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int minsum=INT_MAX;
        for(vector<int>v:ghosts){
            int dist=abs(v[0]-target[0])+abs(v[1]-target[1]);
            minsum=min(dist,minsum);
            if((abs(target[0])+abs(target[1]))>=minsum) return false;
        }
        return true;
    }
};
