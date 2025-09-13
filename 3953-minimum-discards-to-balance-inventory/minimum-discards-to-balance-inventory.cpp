class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int i = 0;
        int ans = 0;
        int n = arrivals.size();
        unordered_map<int, int> mp;
        vector<bool> notdiscarded(n, true);
        while (i < n) {
            if (i >= w) {
                if (notdiscarded[i - w] == true) {
                    mp[arrivals[i - w]]--;
                }
            }
            if (mp[arrivals[i]] == m) {
                notdiscarded[i] = false;
                ans++;
            } else {
                mp[arrivals[i]]++;
            }
            i++;
        }
        return ans;
    }
};