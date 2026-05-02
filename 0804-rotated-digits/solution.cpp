class Solution {
public:
    int rotatedDigits(int n) {
        int cnt=0;
        for(int m=1;m<=n;m++){ 
            int i=m;
            bool valid=true;
            bool changed=false;
            while(i!=0){
                int digit=i%10;
                if(digit==3 || digit==4 || digit==7) {
                    valid=false; 
                    break;}
                else if(digit==2 || digit==5 || digit==6 || digit==9) {
                    changed=true;}
                    i=i/10;
            }
            if(valid && changed) cnt++;
        }  
        return cnt;
    }
};
