class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<pair<int, vector<int>>> q;

        q.push({0, nums1});

        int n = nums1.size();

        set<vector<int>> s;
        s.insert(nums1);

        while (!q.empty()) {

            vector<int> v = q.front().second;
            int count = q.front().first;
            q.pop();

            if (v == nums2) {
                return count;
            }

            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {

                    // Remove this subarray and at at any index k;

                    vector<int> neighbour = v;

                    vector<int> sub(v.begin() + i, v.begin() + j + 1);

                    neighbour.erase(neighbour.begin() + i,
                                    neighbour.begin() + j + 1);

                    int sz = neighbour.size();

                  
                    for (int k = 0; k < sz; k++) {
                        vector<int> next = neighbour;
                        next.insert(next.begin() + k, sub.begin(), sub.end());

                        if (s.find(next) == s.end()) {
                            s.insert(next);
                            q.push({count + 1, next});
                        }
                    }

                    // Our final array will look like
                }
            }
        }

        return -1;
    }
};