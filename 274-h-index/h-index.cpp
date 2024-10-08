class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0;
        int n = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            h = max(h, min(n - i, citations[i]));
        }
        return h;
    }
};