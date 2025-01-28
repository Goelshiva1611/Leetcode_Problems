class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        queue<int> qu;
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            mp[a].push_back(b);
        }
        for (auto it : mp) {
            int node = it.first;
            vector<int> p = it.second;
            for (int i = 0; i < p.size(); i++) {
                indegree[p[i]]++;
            }
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }
        unordered_map<int, set<int>> mp2;
        vector<int> v;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            v.push_back(node);
            vector<int> nbh = mp[node];
            for (int i = 0; i < nbh.size(); i++) {
                int a = nbh[i];
                mp2[a].insert(node);
                for (auto it : mp2[node]) {
                    mp2[a].insert(it);
                }
                indegree[nbh[i]]--;
                if (indegree[nbh[i]] == 0) {
                    qu.push(nbh[i]);
                }
            }
        }
        vector<bool> answer;
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (mp2[b].contains(a)) {
                answer.push_back(true);
            } else {
                answer.push_back(false);
            }
        }
        return answer;
    }
};