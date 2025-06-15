class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>cur;
        unordered_map<int,int>total_cur;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            total_cur[nums[i]]++;
        }
        long long int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            long long int freq1=cur[nums[i]*2];
            long long int freq2=total_cur[nums[i]*2]-cur[nums[i]*2];
            if(nums[i]==0)
                freq2--;
            ans=(ans%mod)+((freq1%mod)*(freq2%mod));
            cur[nums[i]]++;
        }
        return ans;
    }
};