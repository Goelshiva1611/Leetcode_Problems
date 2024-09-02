class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                v.push_back(nums[j]);
            }
            bool flag = false;
            cout<<v.size();
            for (int k = 0; k < v.size() - 1; k++) {
                if (v[k + 1] <= v[k]) {
                    flag = true;
                }
            }
            if (flag == false) {
                return true;
            }
        }
        return false;
    }
};