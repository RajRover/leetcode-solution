class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int idx=0;
        int area=0;
        int left=-1;
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            int right=i;
            while(!st.empty() && heights[st.top()]>heights[i]){
                int h=heights[st.top()];
                st.pop();
                left=(st.empty())?-1:st.top();
                area=max((right-left-1)*h,area);
            }
            st.push(i);
        }
        int right=heights.size();
        while(!st.empty()){
                int h=heights[st.top()];
                st.pop();
                left=(st.empty())?-1:st.top();
                area=max((right-left-1)*h,area);
            }
        return area;
    }
};
