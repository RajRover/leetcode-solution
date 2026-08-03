class Solution {
public:
    bool possible(vector<int>& candies,int guess,long long k){
        long long child=0;
        //int candy=0;
        for(int i=0;i<candies.size();i++){
            //candy=candies[i];
            // if(candy<guess) continue;
            child+=1ll*candies[i]/guess;
        }
        if(child<k) return false;
        return true;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high=accumulate(candies.begin(),candies.end(),0LL)/k;
        int ans=0;
        while(low<=high){
            int guess=low+(high-low)/2;
            if(possible(candies,guess,k)){
                ans=guess;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
        return ans;
    }
};
