class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int r = numbers.size() - 1;
        int l = 0;
        while (l < r) {
            if (numbers[l] + numbers[r] > target)
                r--;
            else if (numbers[l] + numbers[r] < target)
                l++;
            else
                return {l + 1, r + 1};
        }
        return {};
    }
};