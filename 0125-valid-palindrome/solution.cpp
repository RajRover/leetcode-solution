class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int n=s.size();
        if(n<=1) return true;
        int right=n-1;
        while(left<right){
            while(left<right && !isalnum(s[left]) ) left++;
            while(left<right && !isalnum(s[right])) right--;
            if(tolower(s[left])!=tolower(s[right])) return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};
