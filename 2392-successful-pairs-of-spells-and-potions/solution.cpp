class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int> pairs(n);
        for(int i=0;i<n;i++){
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid=(low+high)>>1;
                if((long long)spells[i]*potions[mid]>=success){
                    high=mid-1;
                }
                else low=mid+1;
            }
            pairs[i]=m-low;
        }
        return pairs;
    }
};
