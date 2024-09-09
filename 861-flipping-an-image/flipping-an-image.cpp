class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (vector<int>& t : image) {
            reverse(t.begin(), t.end());
            for (auto& it : t)
                it = !it;
        }
        return image;
    }
};