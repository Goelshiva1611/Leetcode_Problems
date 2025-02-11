
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0;
        int j = part.size() - 1;

        while (true) {
            bool flag = true;
            string p = "";
            while (j < s.size()) {
                if (s.substr(i, part.size()) == part) {
                    s = p + s.substr(j + 1, s.size() - j + 1);
                    flag = false;
                    break;
                } else {
                    p.push_back(s[i]);
                }
                i++;
                j++;
            }
            if (flag == true) {
                break;
            }
            i = 0;
            j = part.size() - 1;
        }
        return s;
    }
};