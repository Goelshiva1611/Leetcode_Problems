class Solution {
public:
    typedef priority_queue<int> pp;
    int minStoneSum(vector<int>& nums, int k) {
        int n=nums.size();
        pp p(nums.begin(),nums.end());
        for(int i=0;i<k;i++)
        {
            int a=p.top();
            p.pop();
            p.push(a-floor(a/2));
        }
        int sum=0;
        while(!p.empty())
        {
            sum+=p.top();
            p.pop();
        }
        return sum;
    }
};