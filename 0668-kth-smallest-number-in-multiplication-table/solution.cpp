class Solution {
public:
    int fn(int m,int n,int guess){
        int row=m;
        int col=1;
        int cnt=0;
        while(row>=1 && col<=n){
            if(row*col>guess){
                row--;
            }
            else{
                cnt+=row;
                col++;
            }
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        int ans=-1;
        while(low<=high){
            int guess=low+(high-low)/2;
            int res=fn(m,n,guess);
            if(res<k){
                //right
                low=guess+1;
            }
            else{
                //possible
                ans=guess;
                high=guess-1;
            }
        }
        return ans;
    }
};
