class Solution {
public:
    int sum(int n){
        int sum=0;
        while(n){
            int digit=n%10;
            sum+=digit*digit;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=slow;
        while(fast!=1 && sum(fast)!=1){
            slow=sum(slow);
            fast=sum(fast);
            fast=sum(fast);
            if(slow==fast) return false;
        }
        return slow;
    }
};
