class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> v;
        priority_queue< pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({abs(x - arr[i]),arr[i]});
        }
        while (!pq.empty()) {
            if (pq.size() <= k) {
                break;
            }
            pq.pop();
        }
        while (!pq.empty()) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};