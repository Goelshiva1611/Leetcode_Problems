class Solution {
public:
    int sumofdigit(int i) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i = i / 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int num = i;
            mp[sumofdigit(num)]++;
        }
        int t = 0;
        for (auto it : mp) {
            if (it.second > t) {
                t = it.second;
            }
        }
        int p = 0;
        for (auto it : mp) {
            if (it.second == t) {
                p++;
            }
        }
        return p;
    }
};