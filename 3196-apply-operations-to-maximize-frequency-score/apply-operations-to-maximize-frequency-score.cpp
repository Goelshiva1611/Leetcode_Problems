class Solution {
public:
    typedef long long int ll;
    bool possiblehai(vector<int> nums, ll k, ll mid, vector<ll>& cumms) {
        ll i = 0;
        ll j = mid - 1;
        while (j < nums.size()) {
            ll m = (i + j) / 2;
            ll leftele = 1ll*(m-i) * nums[m];
            ll p = 0;
            if (m != 0 ) {
                if (i != 0) {
                    p = cumms[m - 1] - cumms[i - 1];

                } else {
                    p = cumms[m - 1];
                }
            }
      
            ll x = leftele - p;
            ll rightele = j - m;
            ll rightsum = rightele * nums[m];
            ll r = cumms[j] - cumms[m];
            ll y = abs(rightsum - r);
            if (x + y <= k) {
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<ll> cumm;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            cumm.push_back(sum);
        }
        // vector cumm ready;

        int low = 1;
        int high = n;
        int score = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (possiblehai(nums, k, mid, cumm)) {
                score = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return score;
    }
};