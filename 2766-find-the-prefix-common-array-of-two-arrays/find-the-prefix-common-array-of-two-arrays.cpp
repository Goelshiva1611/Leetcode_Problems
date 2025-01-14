class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        set<int> st;
        vector<int> c;
        vector<bool> visited(A.size(), false);
        // for (int i = 0; i < n; i++) {
        //     int count = 0;
        //     st.insert(A[i]);
        //     for (int j = 0; j <= i; j++) {
        //         if (st.find(B[j]) != st.end()) {
        //             count++;
        //         }
        //     }
        //     c.push_back(count);
        // }
        int t = 0;
        for (int i = 0; i < n; i++) {
            int a = A[i];
            int b = B[i];

            if (visited[a] == false) {
                visited[a] = true;
            } else {
                t++;
            }

            if (visited[b] == false) {
                visited[b] = true;
            } else {
                t++;
            }

            c.push_back(t);
        }
        return c;
    }
};
