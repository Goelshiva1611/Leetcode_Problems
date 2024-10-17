class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        bool flag = true;
        for (int i = 0; i < n; i++) {
            flag = false;
            for (int j = 1; j < nums[i]; j++) {
                int x=j|j+1;
                if (x == nums[i]) {
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                ans.push_back(-1);
        }
        return ans;
    }
};