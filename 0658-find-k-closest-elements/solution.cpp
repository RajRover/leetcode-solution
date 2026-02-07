// struct cmp {
//     bool operator()(const pair<int,int>& a,const pair<int,int>& b) {
//         // Max-heap based on frequency
//         if(a.second!=b.second) return a.second < b.second;
//         return a.first<b.first;
//     }
// };
// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<pair<int,int>> dist;
//         priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
//         int n=arr.size();
//         for(int i=0;i<n;i++){
//             pair<int,int> val={arr[i],abs(arr[i]-x)};
//             dist.push_back(val);
//         }
//         for(auto it:dist){
//             int element=it.first;
//             int dis=it.second;
//             pair<int,int> curr={element,dis};
//             if(pq.size()<k) {pq.push(curr); continue;}
//             pq.push(curr);
//             pq.pop();
//         }
//         vector<int> ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top().first);
//             pq.pop();
//         }
//         return ans;
//     }
// };
struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        // Max-heap based on distance
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> dist;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int n = arr.size();

        // Step 1: build (element, distance) vector
        for(int i = 0; i < n; i++){
            pair<int,int> val = {arr[i], abs(arr[i] - x)};
            dist.push_back(val);
        }

        // Step 2: maintain max-heap of size k using your style
        for(auto it : dist){
            int element = it.first;
            int dis = it.second;
            pair<int,int> curr = {element, dis};

            if(pq.size() < k) {
                pq.push(curr);
                continue;
            }

            // Only push/pop if the new element is closer than the current farthest
            if(dis < pq.top().second || (dis == pq.top().second && element < pq.top().first)) {
                pq.push(curr);
                pq.pop();
            }
        }

        // Step 3: extract elements from heap
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        // Step 4: sort ascending
        sort(ans.begin(), ans.end());

        return ans;
    }
};

