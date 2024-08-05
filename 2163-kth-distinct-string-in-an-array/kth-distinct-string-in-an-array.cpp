class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, pair<int, int>> mp;
        int p = k;

        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]].first++;
            mp[arr[i]].second = i;
        }
        string ans = "";
        vector<pair<int,string>> v;
        for (auto it : mp) {
            if (it.second.first == 1) {
                v.push_back({it.second.second,it.first});
            }
        }
        sort(v.begin(),v.end());
        if(v.size()>=k)
        {
            return v[k-1].second;
        }
        return ans;
    }
};