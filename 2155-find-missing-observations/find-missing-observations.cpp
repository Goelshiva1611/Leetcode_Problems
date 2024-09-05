class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }
        cout << sum;
        int num = mean * (rolls.size() + n);
        int remain = num - sum;
        vector<int> v;
        map<int, int> mp;
        for (int i = 1; i <= 6; i++) {
            mp[i] = remain / i;
        }
        for (auto& it : mp) {
            int a = it.first;
            int b = it.second;
            cout << a;
            cout << b;
            cout << endl;
            for (int i = 0; i < b; i++) {
                v.push_back(a);
            }
        }
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
                    cout << "hevhgjfghllo";
                    flag = true;
                    break;
                }
                t = t - v[l];
                l++;
                r++;
                if (r != v.size())
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

        // you can also use vector directly and push 6 laks values in the worst
        // case.. unordered map ke use se it become slighly optimized not full;
    }
};