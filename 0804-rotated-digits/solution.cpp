class Solution {
public:
    bool digit(int num){
        bool changed=false;
        while(num){
            int x=num%10;
            num/=10;
            if(x==3 || x==4 || x==7){
                return false;
            }
            if(x==2 || x==5 || x==6 || x==9){
                changed=true;
            }
        }
        return changed;
        
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(digit(i)) cnt++;
        }
        return cnt;
    }
};
