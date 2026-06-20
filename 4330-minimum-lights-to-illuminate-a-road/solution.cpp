class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        if(n==0) return 0;
        vector<bool>covered(n,false);
        vector<int>diff(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int start=max(0LL,(long long)i-lights[i]);
                int end=min((long long)n-1,(long long)i+lights[i]);
                // for(int k=start;k<=end;k++){
                //     covered[k]=true;
                // }
                diff[start]++;
                diff[end+1]--;
            }
        }
        int active=0;
        for(int i=0;i<n;i++){
            active+=diff[i];
            if(active>0){
                covered[i]=true;
            }
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!covered[i]){
                int j=min(n - 1, i + 1);
                covered[j]=true;
                if(j<n-1) covered[j+1]=true;
                if(j>=1) covered[j-1]=true;
                ans++;
            }
        }
        return ans;
    }
};
