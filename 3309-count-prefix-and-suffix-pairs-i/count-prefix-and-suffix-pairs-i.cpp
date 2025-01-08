class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int t = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            string test = words[i];

            for (int j = i + 1; j < n; j++) {
                flag = true;
                if (test.size() <= words[j].size()) {
                    string x = words[j];
                    for (int k = 0; k < x.size(); k++) {
                        if (k >= test.size()) {
                            break;
                        }
                        if (test[k] != x[k]) {
                            flag = false;
                            break;
                        }
                    }
                    int w = test.size() - 1;
                    for (int k = x.size() - 1; k >= 0; k--) {
                        if (w < 0) {
                            break;
                        }
                        if (test[w] != x[k]) {
                            flag = false;
                            break;
                        }
                        w--;
                    }
                }
                if (test.size() <= words[j].size() && flag == true) {
                    t += 1;
                }
            }
        }
        return t;
    }
};