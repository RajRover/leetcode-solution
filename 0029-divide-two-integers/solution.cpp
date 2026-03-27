class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign =true;
        if(dividend==divisor) return 1;
        if(dividend>=0 && divisor<0) sign =false;
        if(dividend<0 && divisor>0) sign =false;
        long long n=abs((long long) dividend);
        long long d=abs((long long) divisor);
        long long ans=0;
        
        while(n>=d){
            long long cnt=0;
            while(n >= d * (1LL << (cnt + 1))){
                cnt++;
            }
            ans+=1<<cnt;
            n -= d * (1LL << cnt);
        }
        if(ans==1<<31 && sign==true) return INT_MAX;
        if(ans==1<<31 && sign==false) return INT_MIN;
        return (sign)?ans:-1*ans;
    }
};
