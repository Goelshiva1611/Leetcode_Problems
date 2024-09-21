class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v1;
        vector<string> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            v1.push_back(stoi(v[i]));
        }
        return v1;
    }
};