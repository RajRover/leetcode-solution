class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        
        // Step 1: Find pivot
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]) { 
                ind = i; 
                break;
            }
        }
        
        // Step 2: If pivot exists, find next bigger element and swap
        if(ind != -1){
            for(int i = n-1; i > ind; i--){
                if(nums[i] > nums[ind]) {
                    swap(nums[i], nums[ind]);
                    break;  // Important: only swap once
                }
            }
        }
        
        // Step 3: Reverse the suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};

