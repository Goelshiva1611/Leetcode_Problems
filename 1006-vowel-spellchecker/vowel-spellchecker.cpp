class Solution {
public:
    string toLower(string p) {
        string ans = "";
        for (auto it : p) {
            if (it >= 65 && it <= 90) {
                ans.push_back(it + 32);
            } else {
                ans.push_back(it);
            }
        }
        return ans;
    }
    string vowelError(string p) {
        string ans = toLower(p);
        for (int i = 0; i < p.size(); i++) {
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' ||
                ans[i] == 'o' || ans[i] == 'u') {
                ans[i] = '*';
            }
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> capitlization;
        unordered_map<string, string> vowel;
        for (int i = 0; i < wordlist.size(); i++) {
            string p = wordlist[i];
            exact.insert(p);
            string lower = toLower(p);
            if (capitlization.find(lower) == capitlization.end()) {
                capitlization[lower] = p;
            }
            string vowelerror = vowelError(p);
            if (vowel.find(vowelerror) == vowel.end()) {
                vowel[vowelerror] = p;
            }
        }
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++) {
            string p = queries[i];
            string lower = toLower(p);
            string vowelerror = vowelError(p);
            if (exact.find(p) != exact.end()) {
                ans.push_back(p);
            } else if (capitlization.find(lower) != capitlization.end()) {
                ans.push_back(capitlization[lower]);
            } else if (vowel.find(vowelerror) != vowel.end()) {
                ans.push_back(vowel[vowelerror]);
            } else {
                ans.push_back("");
            }
        }
        return ans;
    }
};