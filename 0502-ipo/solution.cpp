class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        vector<pair<int,int>> proj; 
        for(int i=0;i<n;i++){
            pair<int,int> p={capital[i],profits[i]};
            proj.push_back(p);}
        sort(proj.begin(),proj.end());
        priority_queue<int> pq;
        int idx=0;
        while(k--){
            while(idx<n){
                if(proj[idx].first>w) break;
                //store
                pq.push(proj[idx].second);
                idx++;
            }
            if(pq.empty()) break;
            int pro=pq.top();
            pq.pop();
            w=w+pro;
        }
        return w;

    }
};
