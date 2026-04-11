class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(int num:nums){
            int k=num;
            while(k){
                if(k%10==digit){
                    cnt++;
                }
                k=k/10;
            }
        }
        return cnt;
    }
};
