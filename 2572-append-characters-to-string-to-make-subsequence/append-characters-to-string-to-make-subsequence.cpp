class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        int i=0;
        int n=s.size();
        while (i < n) {
            if(j==t.size())
                return 0;
            if (t[j] == s[i]) {
                j++;
            }
            i++;
        }
        return t.size()-j;
    }
};