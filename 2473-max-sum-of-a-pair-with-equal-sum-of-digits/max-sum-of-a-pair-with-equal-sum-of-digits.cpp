class Solution {
public:
    map<int, vector<int>> mp;
    int sumofdigits(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            cout<<sumofdigits(v[i]);
            mp[sumofdigits(v[i])].push_back(v[i]);
        }
        int m = 0;
        for (auto it : mp) {
            vector<int> v = it.second;
            if (v.size() >=2) {
                int b = v[v.size() - 1];
                int a = v[v.size() - 2];
                m = max(m, a + b);
            }
        }
        return (m==0)?-1:m;
    }
};