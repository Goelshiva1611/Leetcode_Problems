class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.rbegin(),happiness.rend());
        int i=0;
        long long ans=0;
        while(k--)
        {
            if(happiness[i]-i<0)
                break;
            ans+=happiness[i]-i;
            i++;    
        }
        return ans;
    }
};