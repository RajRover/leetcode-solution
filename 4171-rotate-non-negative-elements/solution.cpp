class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>pos;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
        }
        if (pos.empty()) return nums;
        k=k%pos.size();
        if(k==0) return nums;
        reverse(pos.begin(),pos.begin()+k);
        reverse(pos.begin()+k,pos.end());
        reverse(pos.begin(),pos.end());
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=pos[idx++];
            }
        }
        return nums;
        
    }
};
