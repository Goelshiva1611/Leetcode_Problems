class CombinationIterator {
public:
    vector<string> ans;
    void solve(string perm, int i, int combinationLength, string s) {
        if (i >= perm.size()) {
            cout << "j";
            return;
        }
        string q = s;
        s += perm[i];
        if(s.size()>combinationLength) return ;
        if (s.size() == combinationLength) {
            ans.push_back(s);
        }
        solve(perm, i + 1, combinationLength, s);
        solve(perm, i + 1, combinationLength, q);
    }
    CombinationIterator(string characters, int combinationLength) {
        solve(characters, 0, combinationLength, "");
        cout << ans.size();
        sort(ans.begin(), ans.end(),
             [&](string& a, string& b) { return a > b; });
    }

    string next() {
        string p = "";
        if (ans.size() >= 1) {
            p = ans.back();
            ans.pop_back();
        }
        return p;
    }

    bool hasNext() {
        if (ans.size() >= 1) {
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */