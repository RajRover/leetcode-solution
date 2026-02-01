class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            res[i]=(st.empty())?-1:st.top();
            st.push(nums[i]);
        }
        return res;
    }
};
