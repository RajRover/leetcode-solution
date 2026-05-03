class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int even=0;
        int odd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even++;
            else odd++;
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even--;
            }
            else{
                odd--;
            }
            if(nums[i]%2==0){
                res.push_back(odd);
            }
            else{
                res.push_back(even);
            }
        }
        return res;
        
    }
};
