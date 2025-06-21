class Solution {
public:
    bool find(vector<int>& bloomDay, int m, int k, int mid) {
        int buk = m;
        int n = bloomDay.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = bloomDay[i];
            if (a <= mid) {
                count++;
                if (count == k) {
                    count = 0;
                    ans++;
                }
                if (ans == buk) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;
        if(1ll*m*k>bloomDay.size())
            return -1;
        while (low <high) {
            int mid = low + (high - low) / 2;
            cout << mid;
            cout << endl;
            if (find(bloomDay, m, k, mid)) {
                answer = mid;
                high = mid ;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};