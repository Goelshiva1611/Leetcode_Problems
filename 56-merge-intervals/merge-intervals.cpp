class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        priority_queue<int> pq;
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(intervals[0][0]);
        for (int i = 0; i < n; i++) {
            if (pq.empty()) {
                pq.push(intervals[i][1]);
            } else {
                if (!pq.empty() && pq.top() >= intervals[i][0]) {
                    int a=pq.top();
                    pq.pop();
                    pq.push(max(intervals[i][1],a));
                } else {
                    v.push_back(pq.top());
                    pq.pop();
                    ans.push_back(v);
                    v = {};
                    v.push_back(intervals[i][0]);
                    pq.push(intervals[i][1]);
                }
            }
        }
        if (!pq.empty()) {
            v.push_back(pq.top());
            ans.push_back(v);
        }
        return ans;
    }
};