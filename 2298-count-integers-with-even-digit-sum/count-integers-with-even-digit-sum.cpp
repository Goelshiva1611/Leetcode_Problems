class Solution {
public:
    bool checksum(string& s) {
        int n = 0;
        for (int i = 0; i < s.size(); i++)
            n += s[i] - '0';
        return (n % 2 == 0) ? true : false;
    }
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            string s = to_string(i);
            if (checksum(s))
                count++;
        }
        return count;
    }
};