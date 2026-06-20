class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m,string(n,'#'));
        int i=0;
        int j=0;
        while(i<m-1 || j<n-1){
            ans[i][j]='.'; 
            if(i<m-1 && j<n-1){
                j++;
                ans[i][j]='.';  
                i++;
            }
            
            else if(i<m-1) i++;
            else if(j<n-1) j++;
        }
        ans[m-1][n-1]='.';
        return ans;
    }
};
