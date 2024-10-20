class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> v;
        stack<char> st;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ')') {
                vector<bool> v1;
                while (!st.empty() && (st.top() != '&' && st.top() != '|' &&
                                       st.top() != '!')) {
                    if (st.top() == 'f')
                        v1.push_back(false);
                    if (st.top() == 't')
                        v1.push_back(true);
                    st.pop();
                }
                if (!st.empty() &&
                    (st.top() == '&' || st.top() == '!' || st.top() == '|'))
                    st.pop();
                if (v.size() >= 1 && v[v.size() - 1] == '!')
                    st.push((v1[0] == false) ? 't' : 'f');
                else {
                    if (v1.size() == 1) {
                        st.push((v1[0] == false) ? 'f' : 't');
                    } else if (v1.size() > 1) {
                        bool x = v1[0];
                        char c;
                        if (v.size() >= 1)
                            c = v[v.size() - 1];
                        for (int t = 1; t < v1.size(); t++)
                            x = (c == '|') ? x | v1[t] : x & v1[t];
                        st.push((x == false) ? 'f' : 't');
                    }
                }
                v.pop_back();
            } else {
                if (expression[i] == '&' || expression[i] == '!' ||
                    expression[i] == '|')
                    v.push_back(expression[i]);
                st.push(expression[i]);
            }
        }
        return (st.top() == 'f') ? false : true;
    }
};