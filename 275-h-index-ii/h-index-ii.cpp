class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int n = citations.size();
        for (int i = 0; i < n;i++) {
            int t = n - i;
            cout << t;
            h=max(h,min(t,citations[i]));
        }
        return h;

    }
};
