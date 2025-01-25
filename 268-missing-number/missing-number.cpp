class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int l = 0;
        // int r = n;
        // sort(nums.begin(),nums.end());
        // while (l <r) {
        //     int mid = l + (r - l) / 2;
        //     if (nums[mid] != mid) {
        //         r = mid;
        //     } else {
        //         l = mid +1;
        //     }
        // }
        // return l;   
        int m=nums.size();

        for(int i=0;i<nums.size();i++)
        {
            m=m^i^nums[i];
        }
        return m;
    }
};