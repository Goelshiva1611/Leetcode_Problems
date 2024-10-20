class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        vector<char> v;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (expression[i] == ')') {
                vector<bool> v1;
                while (!st.empty() && (st.top() != '&' && st.top() != '|' &&
                                       st.top() != '!')) {
                    if (st.top() == 'f') {
                        cout << "hanjii";
                        v1.push_back(false);
                    }
                    if (st.top() == 't') {
                        cout << st.size();
                        cout << "ttttttttt";
                        v1.push_back(true);
                    }
                    cout << st.top();
                    st.pop();
                }
                cout << "cd";
                if (!st.empty() &&
                    (st.top() == '&' || st.top() == '!' || st.top() == '|')) {
                    st.pop();
                }
                if (v.size() >= 1 && v[v.size() - 1] == '!') {
                    cout << "hello";
                    if (v1[0] == false) {
                        cout << "bh";
                        st.push('t');
                    } else {

                        st.push('f');
                    }

                    v.pop_back();
                    cout<<v.size();
                } else {
                    if (v1.size() == 1) {
                        if (v1[0] == false)
                            st.push('f');
                        else
                            st.push('t');
                        
                        v.pop_back();

                    } else if (v1.size() > 1) {
                        bool x = v1[0];

                        char c;
                        if (v.size() >= 1) {
                            cout << "jhgcjhvcjhscvjhcvsdjhvcdcj";
                            c = v[v.size() - 1];
                        }
                        for (int t = 1; t < v1.size(); t++) {

                            if (c == '|') {
                                x = x | v1[t];
                            } else {
                                cout<<"hhhh";
                                x = x & v1[t];
                            }
                        }
                        cout << x;
                        v.pop_back();
                        cout<<v.size();
                        if (x == false) {
                            cout << "hj";
                            st.push('f');
                            cout << st.size();
                        } else {
                            st.push('t');
                        }
                    }
                }
            } else {
                if (expression[i] == '&' || expression[i] == '!' ||
                    expression[i] == '|') {
                    v.push_back(expression[i]);
                }
                st.push(expression[i]);
            }
        }
        if (!st.empty()) {
            return (st.top() == 'f') ? false : true;
        }
        return 0;
    }
};