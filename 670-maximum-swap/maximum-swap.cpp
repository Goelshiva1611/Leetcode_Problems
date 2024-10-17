class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v(10, -1);
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int a = s[i] - '0';
            v[a] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 9; j > s[i]-'0'; j--) {
                if (v[j] != -1 && v[j] > i) {
                    char c = j + '0';
                    swap(s[v[j]],s[i]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};