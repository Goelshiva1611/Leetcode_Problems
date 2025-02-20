class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(stoi(nums[i], 0, 2));
        }
        string result = "";
        for (int i = 0; i < pow(2, n); i++) {
            if (st.find(i) == st.end()) {
                bitset<16> nub = i;
                result = nub.to_string();
                return result.substr(16 - n, n);
            }
        }
        return result;
    }
};

/*

class Solution {
public:
    vector<string> result;
    set<string> st;
    int size = 0;
    bool flag = false;
    void solve(string ans) {
        if (ans.size() == size) {
            result.push_back(ans);
            if (st.find(ans) == st.end()) {
                flag = true;
            }
            return;
        }
        for (int i = 0; i <= 1; i++) {
            ans += to_string(i);
            if (flag == false) {
                solve(ans);
            }
            ans.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        size = nums[0].size();
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        string ans = "";
        solve(ans);
        for (int i = 0; i < result.size(); i++) {
            if (st.find(result[i]) == st.end()) {
                return result[i];
            }
        }
        return "";
    }
    // bhailogo fully optimized hai flag ka use hta bhi sakte ho only for
    // optimization
};
*/