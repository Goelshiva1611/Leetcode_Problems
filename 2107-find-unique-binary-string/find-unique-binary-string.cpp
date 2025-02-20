class Solution {
public:
    vector<string> result;
    set<string> st;
    int size = 0;
    void solve(string ans) {
        if (ans.size()==size) {
            result.push_back(ans);
            return;
        }
        for (int i = 0; i <= 1; i++) {
            ans += to_string(i);
            solve(ans);
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
        for(int i=0;i<result.size();i++)
        {
            if(st.find(result[i])==st.end())
            {
                return result[i];
            }
        }
        return "";
    }
};