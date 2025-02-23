class Solution {
public:
    bool hasSameDigits(string s) {
        string p = s;
        while (p.size() != 2) {
            string newstring = "";
            for (int i = 0; i < p.size() - 1; i++) {
                int a = p[i] - '0';
                int b = p[i + 1] - '0';
                int sum = (a + b) % 10;
                newstring += sum;
            }
            p = newstring;
        }
        if (p[0] == p[1]) {
            return true;
        }
        return false;
    }
};