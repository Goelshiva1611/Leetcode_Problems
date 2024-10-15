class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long int count=0;
        int t=0;
        for(int i=n-1;i>=1;i--)
        {
            if(s[i]=='0' && s[i-1]=='1')
            {
                swap(s[i],s[i-1]);
                if(t==0)
                    count++;
                else
                {
                    count+=t+1;
                    cout<<count;
                }
            
            }
            if(s[i]=='0')
            {
                t++;
            }
        }
        return count;
    }
};