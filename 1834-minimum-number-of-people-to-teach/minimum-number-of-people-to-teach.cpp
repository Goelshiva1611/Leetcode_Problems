class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size();
        set<int> sadusers;
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < languages.size(); i++) {
            int person = i + 1;
            vector<int> l = languages[i];
            for (auto it : l)
                mp[person].insert(it);
        }
        for (int i = 0; i < friendships.size(); i++) {
            int u = friendships[i][0];
            int v = friendships[i][1];
            set<int> x = mp[u];
            set<int> y = mp[v];
            bool flag = false;
            for (auto it : x)
                if (y.find(it) != y.end())
                    flag = true;
            if (flag == false) {
                sadusers.insert(u);
                sadusers.insert(v);
            }
        }

        unordered_map<int, int> mp1;
        for (auto it : sadusers) {
            set<int> x = mp[it];
            for (auto i : x) {
                mp1[i]++;
            }
        }
        int ans = INT_MIN;
        for (auto it : mp1) {
            if (it.second > ans) {
                ans = it.second;
            }
        }
        return (ans == INT_MIN) ? 0 : sadusers.size()-ans;
    }
};