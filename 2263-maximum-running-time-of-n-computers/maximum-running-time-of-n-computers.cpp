class Solution {
public:
    bool canpossible(vector<int> batteries, int n, int mid) {
        long long int target = 1ll * n * mid;
        long long int size = batteries.size();
        long long int x = 0;
        for (int i = 0; i < size; i++) {
            target -= min(batteries[i], mid);
            if (target <= 0) {
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long int sum = 0;
        for (int i = 0; i < batteries.size(); i++) {
            sum += batteries[i];
        }
        long long int low = *min_element(batteries.begin(), batteries.end());
        long long int high = sum / n;
        long long int answer = 0;
        while (low <= high) {
            long long int mid = (low + high) / 2;
            if (canpossible(batteries, n, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};