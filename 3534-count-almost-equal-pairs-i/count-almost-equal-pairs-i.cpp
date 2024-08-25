class Solution {
public:
    bool check_pair(long a, long b) {
        string c = to_string(a);
        if (a == b) {
            return true;
        }

        if (a <= 10 || ((a % 10) == 0 and (a % 100) == 0 and (a % 1000) and
                        (a % 10000) and (a % 100000) == 0)) {
            if (b == a * 10 || b == a * 100 || b == a * 1000 ||
                b == a * 10000 || b == a * 100000) {
                return true;
            }
        }

        for (int i = 0; i < c.size(); i++) {
            vector<long> s;
            string d = c;
            for (int j = i + 1; j < c.size(); j++) {
                swap(d[i], d[j]);
                s.push_back(stol(d));
                d = c;
            }
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == b) {
                    return true;
                }
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool flag = true;

                if (check_pair(nums[i], nums[j])) {
                    cout << nums[i] << "__" << nums[j] << endl;
                    count++;
                    flag = false;
                }
                if (flag && check_pair(nums[j], nums[i])) {
                    cout << nums[i] << "__" << nums[j] << "helllo" << endl;
                    count++;
                }
            }
        }
        return count;
    }
};