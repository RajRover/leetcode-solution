class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<drones.size();i++){
            vector<int> drone=drones[i];
            int distance=abs(drone[0]-target[0])+abs(drone[1]-target[1]);
            if(distance>drone[2]){
                continue;
            }
            if(distance<ans){
                idx=i;
            }
            ans=min(distance,ans);
        }
        return idx;
    }
};
