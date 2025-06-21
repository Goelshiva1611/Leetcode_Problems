class Solution {
public:
    bool canwegeneratethisforce(int mid, vector<int>& position, int m) {
        m--;

        int n = position.size();
        for (int i = 1; i < position.size();) {
            int pos = position[i - 1];
            int t = pos + mid;
            if (mid == 999999997) {
                cout << t;
            }
            while (i < n && position[i] < t) {
                i++;
            }
            if (i< n && position[i] >= t) {
                m--;
            }
            if (m == 0) {
                return true;
            }
            i++;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0;
        int high = *max_element(position.begin(), position.end());
        int answer = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            cout<<mid;
            cout<<endl;
            if (canwegeneratethisforce(mid, position, m)) {
                
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};