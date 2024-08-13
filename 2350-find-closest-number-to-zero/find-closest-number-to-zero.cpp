class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i].first=abs(nums[i]);
            v[i].second=nums[i];
        }
        sort(v.begin(),v.end());
        int t=0;
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i].first!=v[i+1].first)
            {
                t=v[i].second;
                break;
            }
            else
            {
                t=v[i+1].second;
            }
        }
        return t;
    }
};