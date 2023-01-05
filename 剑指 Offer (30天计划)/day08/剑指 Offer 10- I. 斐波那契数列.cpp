class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int a = 0, b = 1, res;
        while ( -- n ) {
            res = (a + b) % 1000000007;
            a = b;
            b = res;
        }
        return res;
    }
};