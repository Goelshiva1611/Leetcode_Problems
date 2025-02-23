typedef long long ll;
class Solution {
public:
    vector<ll> converttostline(int side, vector<vector<int>>& points) {
        vector<ll> stline;
        for (int i = 0; i < points.size(); i++) {
            ll x = points[i][0];
            ll y = points[i][1];
            if (y == 0) {
                stline.push_back(x);
            } else if (x == side) {
                stline.push_back(side + y);
            } else if (y == side) {
                stline.push_back(3LL * side - x);
            } else {
                stline.push_back(4LL * side - y);
            }
        }
        sort(stline.begin(), stline.end());
        return stline;
    }
    bool pointsfindable(vector<ll> stline, ll mid, int k, int side) {
        int n = stline.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            int ind = i;
            long long num = stline[i];
            while (count < k && ind < n) {
                auto id =
                    lower_bound(stline.begin() + ind, stline.end(), num + mid);
                if (id != stline.end()) {
                    count++;
                    ind = id-stline.begin();
                    num = stline[ind];
                } else {
                    break;
                }
            }
            if (count >= k && stline[i] + 4ll * side - stline[ind] >= mid) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> stline = converttostline(side, points);
        ll low = 0;
        ll high = 4ll * side;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (pointsfindable(stline, mid, k, side)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};