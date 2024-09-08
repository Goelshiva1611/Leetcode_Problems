class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int t = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] != '0') {
                break;
            }
            t++;
        }
        return num.substr(0, num.size() - t);
    }
};