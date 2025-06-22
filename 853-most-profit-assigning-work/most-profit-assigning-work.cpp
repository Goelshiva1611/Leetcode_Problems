class Solution {
public:
    int binarysearch(vector<vector<int>>& v, int target) {
        int low = 0;
        int high = v.size() - 1;
        int answer = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid][0] <= target) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (answer == -1) {
            return 0;
        }
        return v[answer][1];
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].push_back(difficulty[i]);
            v[i].push_back(profit[i]);
        }
        sort(v.begin(), v.end());
        int t = INT_MIN;
        for (int i = 0; i < n; i++) {
            t = max(v[i][1], t);
            v[i][1] = t;
        }
        int x = worker.size();
        int sum = 0;
        for (int i = 0; i < x; i++) {
            int w = worker[i];
            sum += binarysearch(v, w);
        }
        return sum;
    }
};