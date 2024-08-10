class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string t=words[i];
            bool flag=false;
            for(int j=0;j<t.size();j++)
            {
                char q=t[j];
             flag=false;
                for(int k=0;k<allowed.size();k++)
                {
                    if(q==allowed[k])
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag==false)
                {
                    break;
                }
            }
            if(flag==true)
            {
                count++;
            }
        }
        return count;
    }
};