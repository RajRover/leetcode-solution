class Solution {
public:
    int fib(int n) {
        //base case
        if(n==0 || n==1) return n;
        //take present and trust rest
        int a1=fib(n-1);
        int a2=fib(n-2);
        //final ans
        return a1+a2;
    }
};
