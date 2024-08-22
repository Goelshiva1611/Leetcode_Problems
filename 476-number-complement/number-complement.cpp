class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int i = 0;
        while (num) {
            (num % 2 == 1) ?: ans += pow(2, i);
            num /= 2;
            i++;
        }
        return ans;
    }
};