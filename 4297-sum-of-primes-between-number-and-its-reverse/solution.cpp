class Solution {
public:
    bool prime(int n){
        if(n==0 || n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev=0;
        int num=n;
        while(num!=0){
            int i=num%10;
            rev=rev*10+i;
            num=num/10;
        }
        int a=min(n,rev);
        int b=max(n,rev);
        int sum=0;
        for(int i=a;i<=b;i++){
            if(prime(i)) sum+=i;
        }
        return sum;
    }
};
