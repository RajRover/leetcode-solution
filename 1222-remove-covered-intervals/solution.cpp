class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort start(inc) end(dec)
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
        });
        int start1=intervals[0][0];
        int end1=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            int start2=intervals[i][0];
            int end2=intervals[i][1];
            // contains
            if(end1>=start2 && (end1>=end2) && start1<=start2){
                cnt++;
            }
            start1=start2;
            end1=max(end1,end2);
        }
        return intervals.size()-cnt;
    }
};
