class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MIN;
        for (auto it : s) {
            char a = it;
            int p = (26 - (a - 'a'));
            if (p != 26)
                ans = max(ans, p);
            else
                ans = max(ans, 0);
        }
        return ans;
    }
};