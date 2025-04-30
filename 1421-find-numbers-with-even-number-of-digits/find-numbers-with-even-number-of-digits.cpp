class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            string p=to_string(nums[i]);
            count+=(p.size()%2==0)?1:0;
        }
        return count;
    }

};
