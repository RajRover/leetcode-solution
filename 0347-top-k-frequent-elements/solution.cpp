//min heap
struct cmp {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        // Min-heap based on frequency
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        for(auto &i:freq){
            int element=i.first;
            int f=i.second;
            pair<int,int> curr={element,f};
            if(pq.size()<k) {pq.push(curr); continue;}
            if(f<pq.top().second) continue;
            if(!pq.empty()) pq.pop();
            pq.push(curr);
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first); 
            pq.pop();
        }
        return ans;
        
    }
};
