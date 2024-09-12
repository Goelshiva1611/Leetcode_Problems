class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        int n = allowed.size();
        for (int i = 0; i < n; i++) {
            mp[allowed[i]]++;
        }
        int w = words.size();
        bool flag = true;
        int count = 0;
        for (int i = 0; i < w; i++) {
            string q = words[i];
            flag = true;
            for (int j = 0; j < q.size(); j++) {
                if (mp.find(q[j]) == mp.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                count++;
            }
        }
        return count;
    }
};