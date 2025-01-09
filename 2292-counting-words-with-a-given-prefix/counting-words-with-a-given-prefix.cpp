class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int t = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            flag = true;
            string first = words[i];
            if (pref.size() <=first.size()) {
                for (int j = 0; j < pref.size(); j++) {
                    if (pref[j] != first[j]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag == true && pref.size() <=first.size()) {
                t += 1;
            }
        }
        return t;
    }
};