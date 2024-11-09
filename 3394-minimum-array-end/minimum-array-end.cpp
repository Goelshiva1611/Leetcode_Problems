class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> ans;
        long long p = x;
        int i=1;
        while (i!= n) {
            p=(p+1) |x;            
            i++;
        }
        return p;
    }
};