class Solution {
public:
    long long solve(long long l, long long r) {
        long long p = 0;
        long long L = pow(4, p);
        long long ans = 0;
        long long R = pow(4, p + 1) - 1;
        while (L <= l) {
            bool flag = false;
            if (l >= L && l <= R) {
                if (r <= R) {
                    long long t = r - l + 1;
                    ans += (t * (p + 1));
                    break;
                } else {
                    long long t = R - l + 1;
                    ans += (t * (p + 1));
                    flag = true;
                }
            }
            p++;
            L = pow(4, p);
            R = pow(4, p + 1) - 1;
            if (flag == true) {
                l = L;
            }
        }
        return (ans + 1) / 2;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long u = queries[i][0];
            long long v = queries[i][1];
            ans += solve(u, v);
        }
        return ans;
    }
};

/*

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            priority_queue<int> pq;
            for (int j = l; j <= r; j++) {
                pq.push(floor(log(j) / log(4)) + 1);
            }
            while (!pq.empty()) {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                if (a == b) {
                    ans++;
                    if (a > 1) {
                        pq.push(a - 1);
                        pq.push(a - 1);
                    }
                } else {
                    ans += b;
                    pq.push(a - b);
                }
                if (pq.size() == 1) {
                    ans += pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};
*/