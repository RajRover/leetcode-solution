class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //pahle ye check karo: we need recent item
        stack<int> st;
        int n=nums2.size();
        vector<int> res(n);
        st.push(nums2[n-1]);
        //peechhe se
        res[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            //jab tak galat pop
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
            st.push(nums2[i]);
            
        }

        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=res[i];
        }
        vector<int> ans;
        for(int x:nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};
