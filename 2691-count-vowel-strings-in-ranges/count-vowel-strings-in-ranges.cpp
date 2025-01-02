class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<string> vowel;
        vector<int> beforevector;
        vector<int> v;
        int t = 0;
        for (int i = 0; i < n; i++) {
            string p = words[i];
            if ((p[0] == 'a' || p[0] == 'e' || p[0] == 'i' || p[0] == 'o' ||
                 p[0] == 'u') &&
                (p[p.size() - 1] == 'a' || p[p.size() - 1] == 'e' ||
                 p[p.size() - 1] == 'i' || p[p.size() - 1] == 'o' ||
                 p[p.size() - 1] == 'u')) {
                vowel.push_back(p);
                t++;
            }
            beforevector.push_back(t);
        }
        for (int i = 0; i < queries.size(); i++) {
            v.push_back((queries[i][0] == 0)
                            ? beforevector[queries[i][1]]
                            : beforevector[queries[i][1]] -
                                  beforevector[queries[i][0] - 1]);
        }

        return v;
    }
};