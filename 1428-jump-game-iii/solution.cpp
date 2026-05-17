class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //bfs
        int n=arr.size();
        queue<int> q;
        q.push({start});
        vector<bool> vis(arr.size(),false);
        vis[start]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            // success condition
            if (arr[u] == 0) return true;

            int right = u + arr[u];
            int left  = u - arr[u];
            if (right < n && !vis[right]) {
                q.push(right);
                vis[right] = true;
            }

            if (left >= 0 && !vis[left]) {
                q.push(left);
                vis[left] = true;
            }
        }
        return false;
    }
};
