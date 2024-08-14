class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> v;
        priority_queue<int> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v.push_back(abs(nums[i] - nums[j]));
            }
        }
        nth_element(begin(v),begin(v)+k-1,end(v));       
        return  v[k-1];
    }
};