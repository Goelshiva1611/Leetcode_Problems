class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int count = 1;
        char ch = word[0];
        string s = "";
        int i = 1;
        while (i < n) {
            while (ch == word[i] && count != 9) {
                ch=word[i];
                i++;
                count++;
            }
            s += to_string(count);
            s += ch;
            ch = word[i];
            i++;
            count=1;
        }
        if (count == 1 && ch>=97 && ch<=122) {
            s += to_string(count);
            s += ch;
        }
        return s;
    }
};