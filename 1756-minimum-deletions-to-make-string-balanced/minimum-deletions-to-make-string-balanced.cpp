class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int count = 0;
        int t = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (count > 0) {
                if (s[i] == 'b') {
                    t++;
                    count--;
                }
            }
            if (s[i] == 'a') {
                count++;
            }
        }
        return t;
    }
};