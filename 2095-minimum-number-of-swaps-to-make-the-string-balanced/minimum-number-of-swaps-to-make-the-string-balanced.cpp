class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            }
            if (s[i] == '[')
                st.push(s[i]);
        }
        return (st.size() + 1) / 2;
    }
};