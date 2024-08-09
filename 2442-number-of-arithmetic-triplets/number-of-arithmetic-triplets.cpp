class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++) {
            int a=nums[i];
            for(int j=i+1;j<=n-2;j++)
            {
                if(nums[j]-a==diff)
                {
                    for(int k=j+1;k<=n-1;k++)
                    {
                        if(nums[k]-nums[j]==diff)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};