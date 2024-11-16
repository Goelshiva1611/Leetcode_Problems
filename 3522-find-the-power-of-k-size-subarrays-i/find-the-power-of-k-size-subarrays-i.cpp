class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<int> v;
        for (int i = 0; i < k; i++) {
            v.push_back(nums[i]);
        }
        int j = k - 1;
        int i = 0;
        while (j < nums.size()) {
            bool flag = false;
            for (int q = i; q < v.size() - 1; q++) {
                if (v[q + 1] - v[q] != 1) {
                    ans.push_back(-1);
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                ans.push_back(v[v.size() - 1]);
            }
            v[i] = 0;
            j++;
            i++;
            if(j<nums.size())
            v.push_back(nums[j]);
        }
        return ans;
    }
};