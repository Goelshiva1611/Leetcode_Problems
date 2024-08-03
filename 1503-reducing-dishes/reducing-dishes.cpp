class Solution {
public:
    int n;
    vector<vector<int>>v;
    int solve(vector<int>& satisfaction, int t, int i) {
        if (i >= n) {
            return 0;
        }
        if(v[t][i]!=-1)
        {
            return v[t][i];
        }

        int take = satisfaction[i] * t + solve(satisfaction, t + 1, i + 1);
        int notake = solve(satisfaction, t, i + 1);
        return v[t][i]=max(take, notake);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        v.clear();
        v.resize(504,vector<int>(502,-1));
        sort(satisfaction.begin(),satisfaction.end());
        n = satisfaction.size();
        return solve(satisfaction, 1, 0);
    }
};