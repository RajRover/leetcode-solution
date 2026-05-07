class Solution {
public:

    long long sqrt(long long n){

        long long low = 1;
        long long high = n;
        long long ans = 1;

        while(low <= high){

            long long mid = low + (high-low)/2;

            if(mid <= n/mid){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int arrangeCoins(int n) {

        return (sqrt(8LL*n + 1) - 1) / 2;
    }
};
