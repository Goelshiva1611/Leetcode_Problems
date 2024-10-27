class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        int n=nums.size();
        int j=n-1;
        int m=0;
        while(!st.empty())
        {
            int x=nums[j];
            while(st.size()>0 && nums[st.top()]<=x)
            {
                m=max(m,j-st.top());
                st.pop();
            }
            j--;
        }
        return m;
    }
};