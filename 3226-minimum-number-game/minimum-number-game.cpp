class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n)
        {
            int a=nums[i];
            int b=nums[i+1];
            ans.push_back(b);
            ans.push_back(a);
            i+=2;
        }
        return ans;
    }
};