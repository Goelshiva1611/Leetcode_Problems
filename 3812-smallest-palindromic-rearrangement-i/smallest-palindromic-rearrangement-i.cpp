class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        string answer1 = "";
        string answer2 = "";
        char last='a';
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (mp[ch] % 2 != 0) {
                last = ch;
                flag = false;
            }
            int p = mp[ch] / 2;
            while (p != 0) {
                answer1 += ch;
                p--;
            }
        }
        string p = "";
        if (flag == false) {
            
            p = answer1 + last ;
            reverse(answer1.begin(),answer1.end());
            p+=answer1;
            return p;
        }
        p = answer1;
        reverse(answer1.begin(),answer1.end());
        p+=answer1;
        return p;
    }
};