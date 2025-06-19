class Solution {
public:
    typedef long long int ll;
    ll cost_cal(vector<int>& nums, vector<int>& cost, int mid) {
        ll answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            ll d = abs(mid - nums[i]);
            answer += (ll)(d * cost[i]);
        }
        return answer;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll low = *min_element(nums.begin(), nums.end());
        ll high = *max_element(nums.begin(), nums.end());
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cost1 = cost_cal(nums, cost, mid);
            ll cost2 = cost_cal(nums, cost, mid + 1);
            if (cost1 <= cost2) {
                answer = cost1;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};