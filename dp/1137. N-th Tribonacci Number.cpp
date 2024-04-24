class Solution {
public:
    int t[38];

    int solve(int n) {
        if (n <= 1)
            return n;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;

        if (t[n] != -1) {
            return t[n];
        }

        int a = solve(n - 1);
        int b = solve(n - 2);
        int c = solve(n - 3);

        return t[n] = a + b + c;
    }

    int tribonacci(int n) {
        // memset(t, -1, sizeof(t));
        if (n == 0)
            return 0;
        if (n <= 2)
            return 1;

        int a = 0, b = 1, c = 1, d = 0;

        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }

        return d;

        return solve(n);
    }
};
