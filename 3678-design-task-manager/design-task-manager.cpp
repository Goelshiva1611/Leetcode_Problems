class TaskManager {
public:
    set<pair<int, int>> st;
    unordered_map<int, int> mp;
    unordered_map<int, int> s;
    TaskManager(vector<vector<int>>& tasks) {

        for (auto it : tasks) {
            vector<int> p = it;
            st.insert({-it[2], -it[1]});
            mp[it[1]] = it[0];
            s[it[1]] = it[2];
        }
    }

    void add(int userId, int taskId, int priority) {
        st.insert({-priority, -taskId});
        mp[taskId] = userId;
        s[taskId] = priority;
    }
    void edit(int taskId, int newPriority) {
        st.erase({-s[taskId], -taskId});
        st.insert({-newPriority, -taskId});
        s[taskId] = newPriority;
    }

    void rmv(int taskId) {
        mp.erase(taskId);
        st.erase({-s[taskId], -taskId});
        s.erase(taskId);
        pair<int, int> p = *st.begin();
        int pid = abs(p.first);
        int tid = abs(p.second);
        cout << pid;
        cout << tid;
        cout << endl;
    }

    int execTop() {
        if (st.empty()) {
            return -1;
        }
        pair<int, int> p = *st.begin();
        int pid = abs(p.first);
        int tid = abs(p.second);
        int ans = mp[tid];
        rmv(tid);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */