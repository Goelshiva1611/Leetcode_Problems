class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        vector<int> v;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < n; j++) {
                v.push_back(i + 1);
            }
        }
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }
        cout << sum;
        int num = mean * (rolls.size() + n);
        int remain = num - sum;
        cout << num;
        if (remain <= 0) {
            return {};
        }
        if (n * 6 < remain) {
            return {};
        } else {
            int l = 0;
            int r = n - 1;
            int t = 0;
            for (int q = 0; q < n; q++) {
                t += v[q];
            }
            bool flag = false;
            while (r < v.size()) {
                if (t == remain) {
                    cout << "hello";
                    flag = true;
                    break;
                }
                t = t - v[l];
                l++;
                r++;
                t = t + v[r];
            }
            if (flag == true) {
                vector<int> answer;
                cout << l;
                cout << r;
                for (int p = l; p <= r; p++) {
                    answer.push_back(v[p]);
                }
                return answer;
            }
        }
        return {};
    }
};