class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (arr.size() != target.size()) {
            return false;
        }
        int n = target.size();
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());
        for (int i = 0; i < n; i++) {
            if (arr[i] != target[i]) {
                return false;
            }
        }
        return true;
    }
};