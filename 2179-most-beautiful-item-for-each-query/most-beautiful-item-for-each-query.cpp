class Solution {
public:
    int binarysearch(vector<vector<int>>& items, int p, vector<int>& beauty) {
        int i = 0;
        int j = items.size() - 1;
        while (i <= j) {
            int mid = j + ((i - j) / 2);
            if (items[mid][0] <= p) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        if (j >= 0 && j < items.size())
            return beauty[j];
        return 0;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans;
        sort(items.begin(), items.end());
        vector<int> beauty(items.size(), 0);
        int maxbeauty = 0;
        for (int i = 0; i < items.size(); i++) {
            if (items[i][1] > maxbeauty) {
                beauty[i] = items[i][1];
                maxbeauty = items[i][1];
                cout<<beauty[i];
            } else {
                beauty[i] = maxbeauty;
                cout<<beauty[i];
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(binarysearch(items, queries[i], beauty));
        }
        return ans;
    }
};