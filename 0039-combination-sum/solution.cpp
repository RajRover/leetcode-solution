class Solution {
public:
    void fn(vector<int>& candidates, int n,int target,int idx,int sum,vector<int> &diary,vector<vector<int>> &res){
        //base condition
        if(idx==n){
            if(sum==target){
                res.push_back(diary);
            }
            return;
        }
        //nhi lena hai
        fn(candidates,n,target,idx+1,sum,diary,res);
        //lena hai
        if(sum+candidates[idx]<=target){
            //choices
            diary.push_back(candidates[idx]);
            sum+=candidates[idx];
            fn(candidates,n,target,idx,sum,diary,res);
            diary.pop_back();
            sum-=candidates[idx];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> diary;
        int sum=0;
        int n=candidates.size();
        fn(candidates,n,target,0,sum,diary,res);
        return res;
    }
};
