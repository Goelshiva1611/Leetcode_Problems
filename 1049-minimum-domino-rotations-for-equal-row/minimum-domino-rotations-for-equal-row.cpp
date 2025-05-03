class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int p = 0, count = 0, count1 = 0, n = tops.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[tops[i]]++;
            mp[bottoms[i]]++;
        }
        for (auto it : mp)
            if (it.second >= n)
                p = it.first;
        for (int i = 0; i < n; i++) {
            if (tops[i] != p) {
                if (bottoms[i] != p)
                    return -1;
                else
                    count++;
            }
            if (bottoms[i] != p) {
                if (tops[i] != p)
                    return -1;
                else
                    count1++;
            }
        }
        return min(count, count1);
    }
};