class Solution {
public:
    int minGroups(vector<vector<int>>& times) {
        int count = 0;
        sort(times.begin(), times.end(),
             [&](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        int n = times.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (pq.empty()) {
                count++;
                pq.push(times[i][1]);
            } else {
                if (!pq.empty() && pq.top() < times[i][0]) {
                    pq.pop();
                    pq.push(times[i][1]);
                } else {
                    count++;
                    pq.push(times[i][1]);
                }
            }
        }
        return count;
    }
};