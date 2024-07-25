class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string>ans;
        int bit = -1;
        for(int i=0;i<n;i++){
            if(bit!=groups[i]) {
                ans.push_back(words[i]);
                bit = groups[i];
                }
        }
        return ans;
    }
};