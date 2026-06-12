class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEven=0;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                sumEven+=nums[i];
            }
        }
        int n=queries.size();
        for(int i=0;i<n;i++){
            if(nums[queries[i][1]]%2==0){
                sumEven-=nums[queries[i][1]];
            }
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0){
                sumEven+=nums[queries[i][1]];
            }
            res.push_back(sumEven);
        }
        return res;
    }
};
