class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s1 = stoi(event1[0].substr(0, 2)) * 100;
        int ss1 = stoi(event1[0].substr(3, 2));
        int e1 = stoi(event1[1].substr(0, 2)) * 100;
        int ee1 = stoi(event1[1].substr(3, 2));

        int s2 = stoi(event2[0].substr(0, 2)) * 100;
        int ss2 = stoi(event2[0].substr(3, 2));
        int e2 = stoi(event2[1].substr(0, 2)) * 100;
        int ee2 = stoi(event2[1].substr(3, 2));

        if (max(s1 + ss1, s2 + ss2) <= min(e1 + ee1, e2 + ee2)) {
            return true;
        }
        return false;
    }
};