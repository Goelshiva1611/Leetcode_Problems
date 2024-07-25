class Solution {
public:
    vector<int> p;
    int solve(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        if (p[n] != -1) {
            return p[n];
        }
        int a = solve(n - 1);
        int b = solve(n - 2);
        int c = solve(n - 3);

        return p[n] = a + b + c;
    }
    int tribonacci(int n) {
        p.clear();
        p.resize(40, -1);
        return solve(n);
    }
};