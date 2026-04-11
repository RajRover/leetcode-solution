class Solution {
public:
    bool prime(int num){
        if(num<2) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i&1){
                //odd
                if(!prime(nums[i])) continue;
                while(prime(nums[i])){
                    nums[i]++;
                    cnt++;
                }
            }
            else{
                //even
                if(prime(nums[i])) continue;
                while(!prime(nums[i])){
                    nums[i]++;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
