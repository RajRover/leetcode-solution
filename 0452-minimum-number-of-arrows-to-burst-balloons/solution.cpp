class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //case 2 type
        //sort by end
        sort(points.begin(), points.end(), [](auto &a, auto &b){
        return a[1] < b[1];
        });

        int start1=points[0][0];
        int end1=points[0][1];
        int arrow=1;
        for(int i=1;i<points.size();i++){
            int start2=points[i][0];
            int end2=points[i][1];
            //no overlap
            if(end1<start2){
                arrow++;
                start1=start2;
                end1=end2;
            }

        }
        return arrow;
    }
};
