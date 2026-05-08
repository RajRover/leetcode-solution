class Solution {
public:
    vector<bool> isPrime;

    void buildSieve(int max_el) {
        isPrime.resize(max_el + 1, true);

        if(max_el >= 0) isPrime[0] = false;
        if(max_el >= 1) isPrime[1] = false;

        for(int i = 2; i * i <= max_el; i++) {
            if(isPrime[i]) {
                for(int multiple = i * i; multiple <= max_el; multiple += i) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // fill map
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int max_el = *max_element(nums.begin(), nums.end());

        buildSieve(max_el);

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        unordered_set<int> seen;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int i = q.front();
                q.pop();

                if(i == n - 1) return steps;

                // left
                if(i - 1 >= 0 && !vis[i - 1]) {
                    q.push(i - 1);
                    vis[i - 1] = true;
                }

                // right
                if(i + 1 < n && !vis[i + 1]) {
                    q.push(i + 1);
                    vis[i + 1] = true;
                }

                // prime teleport already used
                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                // jump to multiples
                for(int multiple = nums[i]; multiple <= max_el; multiple += nums[i]) {

                    if(!mp.contains(multiple)) continue;

                    for(auto j : mp[multiple]) {

                        if(!vis[j]) {
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return -1;
    }
};
