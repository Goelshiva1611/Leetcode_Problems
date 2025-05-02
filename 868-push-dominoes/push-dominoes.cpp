class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int p = 0;
        stack<int> st;
        string result(dominoes.size(), '.');
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                if (!st.empty()) {
                    while (p <= i) {
                        result[p] = 'R';
                        p++;
                    }
                    st.pop();
                }
                p = i;
                st.push(i);

            } else if (dominoes[i] == 'L') {
                if (!st.empty()) {
                    int l = st.top();
                    int r = i;
                    st.pop();
                    int size = r - l + 1;
                    cout<<size;
                    bool flag = true;
                    if (size % 2 == 0) {
                        flag = true;
                    } else {
                        flag = false;
                    }
                    int newsize = size / 2;
                    while (newsize != 0) {
                        result[l] = 'R';
                        l++;
                        newsize--;
                    }
                    newsize = size / 2;
                    if (flag == false) {
                        l++;
                    }
                    while (newsize != 0) {
                        result[l] = 'L';
                        l++;
                        newsize--;
                    }
                    p=i;
                } else {
                    int size = i - p + 1;
                    while (size--) {
                        result[p] = 'L';
                        p++;
                    }
                    p = i;
                }
            }
        }
        if (!st.empty()) {
            int p=st.top();
            while (p<=n) {
                result[p] = 'R';
                p++;
            }
            st.pop();
        }
        return result;
    }
};