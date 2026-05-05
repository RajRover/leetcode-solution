class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> start;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            start.push_back({intervals[i][0],i});
        }
        sort(start.begin(),start.end());
        for(int i=0;i<n;i++){
            int end=intervals[i][1];
            auto it=lower_bound(start.begin(),start.end(),make_pair(end,0));
            if(it!=start.end()){
                res[i]=it->second;
            }
        }
        return res;
        
        
    }
};


// for(int i=0;i<n;i++){
        //     int end=intervals[i][1];
        //     int row=0;
        //     int small=INT_MAX;
        //     while(row<n){
        //         //int small=
        //         if((intervals[row][0]>=end) && intervals[row][0]==min(intervals[row][0],small)){
        //             if(intervals[row][0]==min(intervals[row][0],small)){
        //                 res[i]=row;
        //             }
        //             small=intervals[row][0]; 
        //         }
        //         row++;
        //     }
        // }
        // return res;
