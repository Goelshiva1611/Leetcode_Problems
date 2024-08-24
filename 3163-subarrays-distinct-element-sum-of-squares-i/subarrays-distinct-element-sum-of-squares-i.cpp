class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= n - i; k++) {
                set<int> st;
                for (int j = k; j < k + i; j++)
                    st.insert(nums[j]);
                sum += st.size() * st.size();
            }
        }
        return sum;
    }
};