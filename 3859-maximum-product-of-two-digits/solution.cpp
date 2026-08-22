class Solution {
public:
    int maxProduct(int n) {
        int x1=0;
        int x2=0;
        int num=n;
        while(num){
            int digit=num%10;
            if(digit>=x1){
                x2=x1;
                x1=digit;
            }
            else if(digit>=x2){
                x2=digit;
            }
            num=num/10;
        }
        return x1*x2;
    }
};
