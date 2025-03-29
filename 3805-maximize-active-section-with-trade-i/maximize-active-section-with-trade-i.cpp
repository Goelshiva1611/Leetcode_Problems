class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int i = n - 1;
        bool flag = false;
        int count = 0;
        vector<int> v;
        while (i >= 0) {
            flag = false;
            while (i >= 0 && s[i] == '0') {
                count++;
                i--;
                flag = true;
            }
            if (flag == true)
                v.push_back(count);
            i--;
            count = 0;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        if (v.size() == 1) {
            return mp['1'];
        }
        if (s[0] == '0') {
            v.pop_back();
        }
        reverse(v.begin(), v.end());
        count = 0;
        int c = 0;
        int p = 0;
        int maxsum = 0;
        flag = true;
        int t = 0;
        if (v.size() == 0) {
            return mp['1'];
        }
        if (s[0] == '0' && v.size() == 0) {
            return mp['1'];
        }
        i = 0;
        while (i < n) {
            flag = true;
            count = 0;
            while (i < n && s[i] == '0') {
                count++;
                i++;
            }
            while (i < n && s[i] == '1') {
                c++;
                i++;
                flag = false;
            }
            if (flag == false) {
                if (t < v.size())
                    maxsum = max(maxsum, count + mp['1'] + v[t]);
                else {
                    maxsum = max(maxsum, count + mp['1']);
                }
                t++;
            }
        }
        return maxsum;
    }
};

/*
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> l0;
        vector<int> r0;
        vector<int> l1;
        vector<int> r1;
        vector<int> v;
        int i = 0;
        bool flag = true;
        int prevone = 0;
        int prevzero = 0;
        int count0 = 0;
        int count1 = 0;
        vector<int> answer;
        int p = 0;
        while (i < n) {
            flag = true;
            if (s[i] == '0') {
                p++;
            }

            while (i < n && s[i] == '0') {
                count0++;
                i++;
            }
            if (s[i] == '1') {
                answer.push_back(i);
            }
            while (i < n && s[i] == '1') {
                count1++;
                i++;
                flag = false;
            }
            if (flag == false) {
                // cout << count0;
                // cout << count1;
                v.push_back(count1);
                l0.push_back(count0);
                l1.push_back(prevone);
                prevone = count1;
                count1 = 0;
                count0 = 0;
            }
        }

        prevone = 0;
        prevzero = 0;
        count0 = 0;
        count1 = 0;
        i = n - 1;

        while (i >= 0) {

            flag = true;

            while (i >= 0 && s[i] == '0') {
                count0++;
                i--;
            }
            while (i >= 0 && s[i] == '1') {
                count1++;
                i--;
                flag = false;
            }
            if (flag == false) {
                v.push_back(count1);
                r0.push_back(count0);
                r1.push_back(prevone);
                prevone = count1;
                count1 = 0;
                count0 = 0;
            }
        }

        reverse(r0.begin(), r0.end());
        reverse(r1.begin(), r1.end());

        int maxsum = 0;
        int sum = 0;
        int k = 0;
        vector<int> m;
        for (int i = 0; i < r0.size(); i++) {
            sum += l1[i];
            sum += r1[i];
            sum += v[i];
            sum += r0[i];
            sum += l0[i];
            maxsum = max(maxsum, sum);
            sum = 0;
        }
        for (int i = 0; i < r0.size(); i++) {
            sum += l1[i];
            sum += r1[i];
            sum += v[i];
            sum += r0[i];
            sum += l0[i];
            if (sum == maxsum) {
                m.push_back(i);
            }
            sum = 0;
        }
        int count = 0;
        if (p <= 1) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    count++;
                }
            }
            return count;
        }
        cout << maxsum;
        cout << m.size();
        int y = 0;
        int finalmax = 0;
        while (y != m.size()) {
            int maxi = m[y];
            int l = 0;
            for (int i = 0; i < answer[maxi] - l0[maxi] - l1[maxi]; i++) {
                if (s[i] == '1') {
                    l++;
                }
            }
            for (int i = answer[maxi] + r0[maxi] + r1[maxi] + v[maxi]; i < n;
                 i++) {
                if (s[i] == '1') {
                    l++;
                }
            }
            y++;
            finalmax = max(finalmax, maxsum + l);
        }
        return finalmax;
    }
};

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> l0;
        vector<int> r0;
        vector<int> l1;
        vector<int> r1;
        vector<int> v;

        int i = 0;
        bool flag = true;
        int prevone = 0;
        int count0 = 0;
        int count1 = 0;
        vector<int> answer;
        int p = 0;
        while (i < n) {
            flag = true;
            if (s[i] == '0') {
                p++;
            }

            while (i < n && s[i] == '0') {
                count0++;
                i++;
            }
            if (s[i] == '1') {
                answer.push_back(i);
            }
            while (i < n && s[i] == '1') {
                count1++;
                i++;
                flag = false;
            }
            if (flag == false) {

                v.push_back(count1);
                l0.push_back(count0);
                l1.push_back(prevone);
                prevone = count1;
                count1 = 0;
                count0 = 0;
            }
        }

        prevone = 0;
        count0 = 0;
        count1 = 0;
        i = n - 1;

        while (i >= 0) {

            flag = true;

            while (i >= 0 && s[i] == '0') {
                count0++;
                i--;
            }
            while (i >= 0 && s[i] == '1') {
                count1++;
                i--;
                flag = false;
            }
            if (flag == false) {
                v.push_back(count1);
                r0.push_back(count0);
                r1.push_back(prevone);
                prevone = count1;
                count1 = 0;
                count0 = 0;
            }
        }

        reverse(r0.begin(), r0.end());
        reverse(r1.begin(), r1.end());
        int count = 0;
        if (p <= 1) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    count++;
                }
            }
            return count;
        }
        int sum = 0;
        int finalmax = 0;
        vector<int> m;
        for (int j = 0; j < r0.size(); j++) {
            sum += l1[j];
            sum += r1[j];
            sum += v[j];
            sum += r0[j];
            sum += l0[j];
            int l = 0;
            for (int i = 0; i < answer[j] - l0[j] - l1[j]; i++) {
                if (s[i] == '1') {
                    l++;
                }
            }
            for (int i = answer[j] + r0[j] + r1[j] + v[j]; i < n; i++) {
                if (s[i] == '1') {
                    l++;
                }
            }
            finalmax = max(finalmax, sum + l);
            sum = 0;
        }
        return finalmax;
    }
};
*/