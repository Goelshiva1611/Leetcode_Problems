class Solution {

public:
    int checkpossible(vector<int>& quantities, int mid, int m) {
        int n = quantities.size();
        int ans = 0;
        for (auto it : quantities) {
            int a = it;
            if (a % mid != 0) {
                ans += a / mid;
                ans += 1;
            } else {
                ans += a / mid;
            }
        }
        if (ans <= m) {
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end());
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int answer = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkpossible(quantities, mid, n)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};