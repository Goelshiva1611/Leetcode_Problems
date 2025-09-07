class Solution {
public:
    long long bin(long long a) {
        long long  count = 0;
        while (a != 0) {
            long long  rem = a % 2;
            if (rem != 0) {
                count++;
            }
            a = a / 2;
        }
        return count;
    }
    int makeTheIntegerZero(int num1, int num2) {
        long long t = 0;
        long long a = num1 - t * num2;
        if(num2>=num1)
        {
            return -1;
        }
        while (true) {
            t++;
            a = num1 - t * num2;
            long long pow = bin(a);
            if(a<=0)
                return -1;
            if (pow <= t && a>=t) {
                break;
            }
        }
        return t;
    }
};