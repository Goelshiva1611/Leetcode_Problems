class Solution {
public:
    bool canBeValid(string s, string locked) {
        // if (s.size() % 2 != 0) {
        //     return false;
        // }
        // stack<int> open;
        // stack<int> openclose;
        // int n = s.size();
        // for (int i = 0; i < n; i++) {
        //     if (locked[i] == '0') {
        //         openclose.push(i);
        //     } else {
        //         if (s[i] == '(') {
        //             open.push(i);
        //         } else {
        //             if (!open.empty()) {
        //                 open.pop();
        //             } else if (!openclose.empty()) {
        //                 openclose.pop();
        //             } else {
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // while (!open.empty() && !openclose.empty() &&
        //        open.top() < openclose.top()) {
        //     open.pop();
        //     openclose.pop();
        // }
        // return open.empty();

        int open = 0;
        int close = 0;
        int n = s.size();
        if(n%2!=0)
        {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(') {
                open++;
            } else {
                open--;
                if (open < 0) {
                    return false;
                }
            }
        }
        for (int i = n-1; i >=0; i--) {
            if (locked[i] == '0' || s[i] == ')') {
                close++;
            } else {
                close--;
                if (close < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};