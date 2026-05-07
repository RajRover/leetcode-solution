class Solution {
public:
    vector<int> cumulative;
    Solution(vector<int>& w) {
        int n=w.size();
        int num=0;
        for(int i=0;i<n;i++){
            num+=w[i];
            cumulative.push_back(num);
        }
    }
    
    int pickIndex() {
        int n=cumulative.size();
        int total=cumulative[n-1];
        //BS number>random
        int r=rand()%total+1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(cumulative[mid]>=r) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
