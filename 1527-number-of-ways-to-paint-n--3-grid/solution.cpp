class Solution {
public:
    int numOfWays(int n) {
        long long a=6;
        long long b=6;
        long long MOD=1e9+7;
        for(int i=1;i<n;i++){
            long long new_a=(a*3+b*2)%MOD;
            long long new_b=(a*2+b*2)%MOD;
            a=new_a;
            b=new_b;
        }
        return (a+b)%MOD;
    }
};
