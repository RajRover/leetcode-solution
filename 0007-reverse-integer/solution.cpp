class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        string num=to_string(x);
        //int ans=0;
        bool flag=false;
        if(num[0]=='-') flag=true;
        (flag) ? std::reverse(num.begin() + 1, num.end()) : std::reverse(num.begin(), num.end());
        try {
            long long temp_ans = std::stoll(num);
            
            // Dynamically check against 32-bit limits instead of hardcoding
            if (temp_ans > INT_MAX || temp_ans < INT_MIN) {
                return 0;
            }
            
            return static_cast<int>(temp_ans);
        } catch (...) {
            // Catches out_of_range if the reversed string is massive
            return 0; 
        }

    }
};
