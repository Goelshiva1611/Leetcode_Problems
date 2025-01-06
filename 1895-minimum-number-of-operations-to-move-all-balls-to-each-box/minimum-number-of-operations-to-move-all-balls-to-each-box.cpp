class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v;
        int n = boxes.size();
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1')
                v.push_back(i);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int t=0;
            for (int j = 0; j < v.size(); j++) {
                t += abs(v[j] - i);
            }
            ans.push_back(t);
        }
        return ans;
    }
};