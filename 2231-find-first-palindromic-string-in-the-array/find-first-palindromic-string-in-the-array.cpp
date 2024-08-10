class Solution {
public:
    bool ispalindromic(string t) {
        int l = 0;
        int r = t.size() - 1;
        while (l <= r) {
            if (t[l] != t[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        int n = words.size();

        for (int i = 0; i < n; i++) {
            if (ispalindromic(words[i])) {
                return words[i];
            }
        }
        return ans;
    }
};