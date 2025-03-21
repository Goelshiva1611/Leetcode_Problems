class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> indegree;
        int n = numCourses;
        for (int i = 0; i < n; i++) {
            indegree[i] = 0;
        }
        queue<int> qu;
        for (int i = 0; i < prerequisites.size(); i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (auto it : indegree) {
            if (it.second == 0) {
                qu.push(it.first);
            }
        }
        vector<int> answer;
        while (!qu.empty()) {
            int t = qu.front();
            qu.pop();
            answer.push_back(t);
            for (int i = 0; i < mp[t].size(); i++) {
                int ngh = mp[t][i];
                indegree[ngh]--;
                if (indegree[ngh] == 0) {
                    qu.push(ngh);
                }
            }
        }
        if(answer.size()!=n)
        {
            return {};
        }
        return answer;
    }
};