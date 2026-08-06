class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_val=0;
        unordered_map<char,int>freq;
        for(char ch:tasks){
            freq[ch]++;
            //max_val=max(max_val,freq[ch]);
        }
        // int cnt_max=0;
        // for(auto it:freq){
        //     if(it.second==max_val){
        //         cnt_max++;
        //     }
        // }
        // int ans=(max_val-1)*(n+1)+cnt_max;
        // ans=max(ans,(int)tasks.size());
        // return ans;

        priority_queue<int>pq;
        for(auto it:freq){
            pq.push(it.second);
        }
        int time=0;
        while(!pq.empty()){
        vector<int> temp;
        for(int i=1;i<=n+1;i++){
            if(!pq.empty()){
                int f=pq.top();
                pq.pop();
                f--;
                temp.push_back(f);
            }
        }

        for(int &f:temp){
            if(f>0)
                pq.push(f);
        }

        if(pq.empty())
            time += temp.size();
        else
            time += n+1;
        }
        return time;
    }
};
