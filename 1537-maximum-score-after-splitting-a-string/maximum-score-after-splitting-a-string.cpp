class Solution {
public:
    int maxScore(string s) {
        int zero=0;
        int one=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')            
            {
                zero++;
            }else
            {
                one++;
            }
        }
        int m=0;
        int p=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='0')
            {
                p++;
                m=max(m,p+one);
            }
            else
            {
                one--;
                 m=max(m,p+one);
            }
        }
        return m;
    }
};