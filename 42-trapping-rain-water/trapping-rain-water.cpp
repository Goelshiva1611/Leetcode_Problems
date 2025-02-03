class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            left = max(left, height[i]);
            leftmax[i] = left;
        }
        for (int i = n-1; i>=0; i--) {
            right = max(right, height[i]);
            rightmax[i] = right;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int t=min(leftmax[i],rightmax[i]);
            if(t-height[i]>=0)
            {
                sum+=t-height[i];
            }
        }
        return sum;

    }
};