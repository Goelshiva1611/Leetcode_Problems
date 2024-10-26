class Solution {
public:
    int maxVowels(string s, int k) {
        string p = s.substr(0, k);
        int count = 0;
        
        for (int j = 0; j < k; j++) {
            if (p[j] == 'a' || p[j] == 'e' || p[j] == 'i' || p[j] == 'o' ||
                p[j] == 'u')
                count++;
        }
        cout<<count;
        int m = count;
        int q = 0;
        for (int i = k; i < s.size(); i++) {
            if (s[q] == 'a' || s[q] == 'e' || s[q] == 'i' || s[q] == 'o' ||
                s[q] == 'u')
                count--;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
                count++;
            q++;
            m = max(m, count);
        }
        m = max(m, count);
        return m;
    }
};