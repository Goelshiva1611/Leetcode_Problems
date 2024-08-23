class Solution {
public:
    int bitwiseComplement(int n) {
        int num = n;
        int ans = 0;
        int i = 0;
        if (n == 0) {
            return 1;
        }
        while (num) {
            (num % 2 == 1) ?: ans += pow(2, i);
            num /= 2;
            i++;
        }
        return ans;
    }
};