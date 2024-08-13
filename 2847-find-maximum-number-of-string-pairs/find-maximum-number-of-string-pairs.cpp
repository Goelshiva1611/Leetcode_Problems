class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        vector<string>dummywords(n);
        dummywords=words;
        for(int i=0;i<n;i++)
        {
            reverse(dummywords[i].begin(),dummywords[i].end());
        }       
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(dummywords[j]==words[i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};