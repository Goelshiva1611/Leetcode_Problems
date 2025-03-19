class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int m=0;
        for(int i=0;i<n;)
        {
            if(nums[i]==0)
            {
                cout<<i;
                m++;
                int p=i;
                if(p+3>n)
                {
                    return -1;
                }else
                {
                    int a=nums[p+1];
                    int b=nums[p+2];
                    nums[p]=1;
                    nums[p+1]=!a;
                    nums[p+2]=!b;
                }
            }
            i++;
        }
        return m;
    }
};