class Solution {
public:
    char findKthBit(int n, int k) {
        float length = pow(2, n) - 1;
        if (n == 1)
            return '0';
        if (k < ceil(length / 2))
            return findKthBit(n - 1, k);
        else if (k == ceil(length / 2))
            return '1';
        else {
            char ch = findKthBit(n - 1, length - (k - 1));
            if (ch == '0')
                return '1';
            else
                return '0';
        }
    }
};
// class Solution {
// public:
//     string invert(string s) {
//         string p;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '0') {
//                 p += '1';
//             } else {
//                 p += '0';
//             }
//         }
//         return p;
//     }
//     char findKthBit(int n, int k) {
//         string s = "0";
//         string p = "";
//         if (n == 1 && k == 1) {
//             return '0';
//         }
//         for (int i = 1; i < n; i++) {
//             string x = invert(s);
//             reverse(x.begin(), x.end());
//             p = s + "1" + x;
//             s = p;
//         }
//         return p[k - 1];
//     }
// };