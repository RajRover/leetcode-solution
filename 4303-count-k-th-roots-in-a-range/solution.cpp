class Solution {
public:
    int power(int x,int k){
        if(k==0) return 1;
        int val=power(x,k/2);
        int res=val*val;
        if(k%2==1) res=res*x;
        return res;
    }
    int countKthRoots(int l, int r, int k) {
        if (k==1) return r-l+1;
        int i=0;
        while(true){
            if(power(i,k)<l) i++;
            else break;
        }
        int cnt=0;
        while(power(i,k)<=r){
            cnt++;
            i++;
        }
        return cnt;
    }
};
