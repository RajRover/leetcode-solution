class Solution {
public:
    double solve(double x,long long n){
        if(n==0) return 1.0;
        double val=myPow(x,n/2);
        double res=val*val;
        if(n%2==1){
            res=x*res;
        }
        return res;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        return solve(x,N);
    }
};
