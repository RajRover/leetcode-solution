class Solution {
public:
    int fn(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            n=n/10;
            sum+=d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(true){
            slow=fn(slow);
            fast=fn(fast);
            fast=fn(fast);
            if (fast == 1) return true;
            if(slow==fast) return false;
        }
        return true;
    }
};
