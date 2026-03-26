class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets=1<<nums.size();
        vector<vector<int>> ans;
        for(int j=0;j<subsets;j++){
            vector<int> temp;
            for(int i=0;i<nums.size();i++){       
                if(j&(1<<i)){//set
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
