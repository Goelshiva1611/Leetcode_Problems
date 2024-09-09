class Solution {
public:
    bool check(int d, vector<int>& start, int mid) {
        long long a = start[0];
        for (int i = 1; i < start.size(); i++)
            if (a + mid >= start[i] && start[i] + d >= a + mid)
                a += mid;
            else if (a + mid < start[i])
                a = start[i];
            else
                return false;
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long l = 0, ans = 0, mid = 0;
        long long r = start[start.size() - 1] + d;
        while (l <= r) {
            mid = (r + l) / 2;
            if (check(d, start, mid)) {
                l = mid + 1;
                ans = mid;
            } else
                r = mid - 1;
        }
        return ans;
    }
};