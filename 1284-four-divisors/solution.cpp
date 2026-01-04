class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            ans += get4div(n);
        }
        return ans;
    }

private:
    int get4div(int n) {
        int sum = 1 + n;
        int cnt = 2;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;

                if (i * i != n) {
                    cnt++;
                    sum += n / i;
                }

                if (cnt > 4) return 0; 
            }
        }
        return (cnt == 4) ? sum : 0;
    }
};

