class Solution {
public:
    bool palindrome(string ascii){
        int left=0;
        int right=ascii.size()-1;
        while(left<=right){
            if(ascii[left]!=ascii[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string ascii="";
        for(char ch:s){
            int num=int(ch);
            bitset<8>binary(num);
            ascii += binary.to_string(); 
        }
        return (palindrome(ascii))?true:false;
    }
};
