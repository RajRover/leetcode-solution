class Solution {
public:
    int nextInd(vector<int>& nums,int curr,bool fwd){
        int n=nums.size();
        if(nums[curr]==0) return -1;
        if(fwd!=nums[curr]>0) return -1;
        int next=(((curr+nums[curr])%n)+n)%n;
        if(next==curr) return -1;
        return next;
    }
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            int slow=i;
            int fast=i;
            bool fwd=nums[i]>0;
            while(true){
                slow=nextInd(nums,slow,fwd);
                if(slow==-1) break;
                fast=nextInd(nums,fast,fwd);
                if(fast==-1) break;
                fast=nextInd(nums,fast,fwd);
                if(fast==-1) break;
                if(slow==fast) break;//cycle there and check for direction and cycle length
            }
            int curr=i;
            //mark visited
            while(curr!=-1 && nums[curr]!=0 && nums[curr]>0==fwd){
                int next=nextInd(nums,curr,fwd);
                nums[curr]=0;
                curr=next;
            }
            //check for direction and cycle length
            if(slow==fast){
                if(slow!=-1 && nextInd(nums,slow,fwd)!=slow){
                    return true;
                }
            }
        }
        return false;
    }
};
