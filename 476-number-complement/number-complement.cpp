class Solution {
public:
    string decimalTobinary(int n) {
        string s = "";
        while (n) {
            s = s + to_string(n % 2);
            n = n / 2;
        }
        return s;
    }
    int binaryTodecimal(string s) {
        int n = s.size();
        int num = 0;
        for (int i = n - 1; i >= 0; i--) {
            num = num + (s[i] - '0') * pow(2, i);
        }
        return num;
    }
    int findComplement(int num) {
        string s = decimalTobinary(num);
        for (int i = 0; i < s.size(); i++) {
            (s[i] == '1') ? s[i] = '0' : s[i] = '1';
        }
        return binaryTodecimal(s);
    }
};