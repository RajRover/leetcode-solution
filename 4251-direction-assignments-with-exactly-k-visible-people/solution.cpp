class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long x, long long b) {
        if (b == 0) return 1;

        long long val = power(x, b / 2);
        long long res = (val * val) % mod;

        if (b % 2 == 1)
            res = (res * x) % mod;

        return res;
    }

    long long fact(int x) {
        long long ans = 1;
        for (int i = 2; i <= x; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }

    int countVisiblePeople(int n, int pos, int k) {
        long long a = 2*fact(n - 1) % mod;
        long long b = (fact(n - 1 - k) * fact(k)) % mod;

        return (a * power(b, mod - 2)) % mod;
    }
};
