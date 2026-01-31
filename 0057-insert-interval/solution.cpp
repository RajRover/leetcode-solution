class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        bool insert=false;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            if(start>=newInterval[0] && insert==false){
                res.push_back(newInterval);
                insert=true;
            }
            res.push_back(intervals[i]);
        }
        if(insert==false) res.push_back(newInterval);
        vector<vector<int>> ans;
        int N=res.size();
        int start1=res[0][0];
        int end1=res[0][1];
        for(int i=1;i<N;i++){
            int start2=res[i][0];
            int end2=res[i][1];
            if(end1>=start2){
                end1=max(end1,end2);
                continue;
            }
            ans.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }
        ans.push_back({start1,end1});
        return ans;
    }
};
