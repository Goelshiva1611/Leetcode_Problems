class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> v;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int m = -1;
            for (int j = i + 1; j < n; j++) {
                m = max(m, arr[j]);
            }
            v.push_back(m);
        }
        return v;
    }
};