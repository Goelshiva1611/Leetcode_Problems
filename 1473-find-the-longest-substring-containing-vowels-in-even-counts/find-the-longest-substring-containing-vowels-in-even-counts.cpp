class Solution {
public:
    int findTheLongestSubstring(string s) {
        string currentstate = "00000";
        int n = s.size();
        int a = 0;
        unordered_map<string, int> mp;
        mp[currentstate] = -1;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                a = currentstate[0] - '0';
                currentstate[0] = ((a + 1) % 2 == 0) ? '0' : '1';
            } else if (s[i] == 'e') {
                a = currentstate[1] - '0';
                cout << a;
                currentstate[1] = ((a + 1) % 2 == 0) ? '0' : '1';
            } else if (s[i] == 'i') {
                a = currentstate[2] - '0';
                currentstate[2] = ((a + 1) % 2 == 0) ? '0' : '1';
            } else if (s[i] == 'o') {
                a = currentstate[3] - '0';
                currentstate[3] = ((a + 1) % 2 == 0) ? '0' : '1';
            } else if (s[i] == 'u') {
                a = currentstate[4] - '0';
                currentstate[4] = ((a + 1) % 2 == 0) ? '0' : '1';
            }
            cout << currentstate;
            if (mp.find(currentstate) != mp.end()) {
                result = max(result, abs(mp[currentstate] - i));
            } else {
                cout << i;
                mp[currentstate] = i;
            }
        }
        return result;
    }
};