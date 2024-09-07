class Solution {
public:
    int num(int n) {
        int sum = 0;
        while (n) {
            int remainder = n % 10;
            sum += remainder * remainder;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        for (int i = 0; i < 10; i++) {
            int t = num(n);
            if (t == 1) {
                return true;
            }
            n = t;
        }
        return false;
    }
};