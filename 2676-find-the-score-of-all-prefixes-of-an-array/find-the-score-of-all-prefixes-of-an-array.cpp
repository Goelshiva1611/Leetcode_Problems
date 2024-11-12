class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<int> findmax(nums.size(), 0);
        int n = nums.size();
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max) {
                max = nums[i];
                findmax[i] = max;
            } else {
                findmax[i] = max;
            }
        }
        vector<int> newarray;
        for (int i = 0; i < n; i++) {
            newarray.push_back(findmax[i] + nums[i]);
        }
        vector<long long> finalarray;
        long long  sum = newarray[0];
        finalarray.push_back(sum);
        for (int i = 1; i < n; i++) {
            sum += newarray[i];
            finalarray.push_back(sum);
        }
        return finalarray;
    }
};