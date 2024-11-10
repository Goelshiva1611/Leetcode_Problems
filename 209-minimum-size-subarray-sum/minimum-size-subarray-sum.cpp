class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        set<int> st;
        int sum=0,r=0,l=0;
        while(r<nums.size())
        {
            sum=sum+nums[r];
            while(sum>=target)
            {
                sum=sum-nums[l];
                st.insert(r-l+1);
                l++;
            }
            r++;
        }
        if(l==0)
        {
            return 0;
        }
        auto p=st.begin();
        return  *p;
    }
};