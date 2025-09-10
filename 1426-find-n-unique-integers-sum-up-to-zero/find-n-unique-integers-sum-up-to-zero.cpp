class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int p = n / 2;
        for (int i = 1; i <= p; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 0) {
            return ans;
        }
        ans.push_back(0);
        return ans;
    }
};