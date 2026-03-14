class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        int n=nums.size();
        vector<int> prefixGcd(n);
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=gcd(mx,nums[i]);
        }
        int i=0;
        int j=n-1;
        sort(prefixGcd.begin(),prefixGcd.end());
        while(j>i){
            prefixGcd[i]=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        if(n%2==0) return accumulate(prefixGcd.begin(),prefixGcd.begin()+j+1,0LL);
        else return accumulate(prefixGcd.begin(),prefixGcd.begin()+j,0LL);
        return -1;
    }
};
