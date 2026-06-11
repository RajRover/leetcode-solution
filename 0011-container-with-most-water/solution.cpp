class Solution {
public:
//bade height ko rakho chhote ko move karo
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int res=0;
        while(i<j){
            if(height[i]<height[j]){
                res=max(res,(j-i)*height[i]);
                i++;
            }
            else{
                res=max(res,(j-i)*height[j]);
                j--;
            }
        }
        return res;
    }
};
