class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target, int i, int currsum,
                vector<int> temp) {
        // Boundary condition
        if (currsum > target)
            return;
        // Base case
        if (currsum == target) {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            // Skip duplicate elements to avoid repetition
            if (j > i && candidates[j] == candidates[j - 1])
                continue;
            // Includsion the candidates[j] and move forward
            temp.push_back(candidates[j]);
            helper(candidates, target, j + 1, currsum + candidates[j], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear(); // clear previous result
        vector<int> temp;
        sort(candidates.begin(),
             candidates.end()); // sort to handle duplicasy easily
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};