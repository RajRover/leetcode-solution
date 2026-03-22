class Solution {
public:
    void fn(int idx,int n,vector<int> diary,vector<vector<int>> &res,vector<int>& nums,vector<bool> used){
        //base
        if(idx==n){
            res.push_back(diary);
            return;
        }
        //make choice
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=true;
            diary.push_back(nums[i]);
            fn(idx+1,n,diary,res,nums,used);
            //reverse the decision
            diary.pop_back();
            used[i]=false;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> diary;
        vector<bool> used(nums.size(), false);
        fn(0,nums.size(),diary,res,nums,used);
        return res;
    }
};
