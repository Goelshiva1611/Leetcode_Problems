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

            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= n - i; j++) {
                    vector<int> rest = v;
                    vector<int> sub(v.begin() + j, v.begin() + j + i);
                    rest.erase(rest.begin() + j, rest.begin() + j + i);
                    int sz = rest.size();
                    for (int k = 0; k <= n - i; k++) {
                        vector<int> next;
                        for (int x = 0; x < k; x++) {
                            next.push_back(rest[x]);
                        }
                        for (int y = 0; y < sub.size(); y++) {
                            next.push_back(sub[y]);
                        }
                        for (int z = k; z < rest.size(); z++) {
                            next.push_back(rest[z]);
                        }
                        if (s.find(next) == s.end()) {
                            s.insert(next);
                            q.push({count + 1, next});
                        }
                    }

                }
            }
        }

        return -1;
    }
};