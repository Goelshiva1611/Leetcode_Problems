class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int t=0;
        vector<int> c;
        vector<bool> visited(A.size(), false);
        for (int i = 0; i < A.size(); i++) {
            visited[A[i]] == false ? visited[A[i]] = true : t++;
            visited[B[i]] == false ? visited[B[i]] = true : t++;
            c.push_back(t);
        }
        return c;
    }
};
