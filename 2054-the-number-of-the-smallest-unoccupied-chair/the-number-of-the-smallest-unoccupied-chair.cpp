class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int m = INT_MAX;
        vector<int> chair(n, 1e9);
        int q = times[targetFriend][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        sort(times.begin(), times.end(),
             [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        for (int i = 0; i < n; i++) {
            m = INT_MAX;
            if (pq.empty()) {
                int end = times[i][1];
                chair[i] = i;
                if (q == times[i][0]) {
                    return i;
                }
                pq.push({end, chair[i]});

            } else {
                while (!pq.empty() && pq.top().first <= times[i][0]) {
                    chair[pq.top().second] = 1e9;
                    pq.pop();
                    cout << m;
                }
                for (int j = 0; j < n; j++) {
                    if (chair[j] == 1e9) {
                        chair[j] = j;
                        if (q == times[i][0]) {
                            return j;
                        }
                        pq.push({times[i][1], j});
                        break;
                    }
                }
            }
        }
        return -1;
    }
};