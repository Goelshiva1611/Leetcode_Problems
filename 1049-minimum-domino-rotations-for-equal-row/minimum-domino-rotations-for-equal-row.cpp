class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int m = bottoms.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[tops[i]]++;
        }
        for (int i = 0; i < m; i++) {
            mp[bottoms[i]]++;
        }
        int p = 0;
        for (auto it : mp) {
            if (it.second >= n) {
                p = it.first;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (tops[i] != p) {
                if (bottoms[i] != p) {
                    return -1;
                } else {
                    count++;
                }
            }
        }
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            if (bottoms[i] != p) {
                if (tops[i] != p) {
                    return -1;
                } else {
                    count1++;
                }
            }
        }
        return min(count, count1);
    }
};