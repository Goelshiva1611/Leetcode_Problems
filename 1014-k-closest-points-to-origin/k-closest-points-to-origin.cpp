class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (int t = 0; t < points.size(); t++) {
            double distance =
                sqrt(points[t][0] * points[t][0] + points[t][1] * points[t][1]);
            pq.push({distance, {points[t][0], points[t][1]}});
        }
        while (pq.size() != k) {
           cout<< pq.top().first;
            pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            vector<int> p;
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            p.push_back(a);
            p.push_back(b);
            ans.push_back(p);
            pq.pop();
        }
        return ans;
    }
};