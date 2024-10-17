class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string p = to_string(num);

        sort(s.begin(), s.end(),
             [&](char a, char b) { return a - '0' > b - '0'; });
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != p[i]) {
                int m=0;
                for (int j = i+1; j < n; j++) {
                    if (p[j] == s[i]) {
                        m = max(m, j);
                    }
                }
                swap(p[i], p[m]);
                return stoi(p);
            }
        }
        return num;
    }
};