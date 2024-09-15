class Solution {
public:
    int findTheLongestSubstring(string s) {
        string currentstate = "00000";
        unordered_map<string, int> mp;
        mp[currentstate] = -1;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                currentstate[0] =
                    (((currentstate[0] - '0') + 1) % 2 == 0) ? '0' : '1';
            else if (s[i] == 'e')
                currentstate[1] =
                    (((currentstate[1] - '0') + 1) % 2 == 0) ? '0' : '1';
            else if (s[i] == 'i')
                currentstate[2] =
                    (((currentstate[2] - '0') + 1) % 2 == 0) ? '0' : '1';
            else if (s[i] == 'o')
                currentstate[3] =
                    (((currentstate[3] - '0') + 1) % 2 == 0) ? '0' : '1';
            else if (s[i] == 'u')
                currentstate[4] =
                    (((currentstate[4] - '0') + 1) % 2 == 0) ? '0' : '1';
            if (mp.find(currentstate) != mp.end())
                result = max(result, abs(mp[currentstate] - i));
            else
                mp[currentstate] = i;
        }
        return result;
    }
};