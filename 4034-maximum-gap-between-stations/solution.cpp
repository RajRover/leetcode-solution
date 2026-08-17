class Solution {
public:
    int maximumGap(string skill, string station) {
        if(skill.size()==1) return 0;

        vector<int> left(skill.size(),0);
        vector<int> right(skill.size(),0);

        // Earliest possible positions
        int pos = 0;
        for(int idx=0; idx<skill.size(); idx++){
            while(station[pos] != skill[idx])
                pos++;
            
            left[idx] = pos;
            pos++;
        }

        // Latest possible positions
        pos = station.size()-1;
        for(int idx=skill.size()-1; idx>=0; idx--){
            while(station[pos] != skill[idx])
                pos--;
            
            right[idx] = pos;
            pos--;
        }

        int ans=0;

        for(int i=0;i<left.size()-1;i++){
            ans=max(right[i+1]-left[i],ans);
        }

        return ans;
    }
};
