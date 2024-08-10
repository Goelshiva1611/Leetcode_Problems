class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         vector<int>& energy, vector<int>& experience) {

        int sum = 0;
        int ans = 0;
        int n = experience.size();
        for (int i = 0; i < n; i++) {
            sum += energy[i];
        }
        ans =max(0,sum - initialEnergy + 1) ;
        cout<<ans;
        cout<<"\n";
        for (int i = 0; i < n; i++) {
            if (initialExperience <= experience[i]) {
                cout<<ans;
                ans += experience[i]-initialExperience + 1;
                initialExperience += experience[i]-initialExperience + 1;
            }
            initialExperience += experience[i];
        }
        return ans;
        // int n=energy.size();
        // int t=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     if(energy[i]>t)
        //     {
        //         t=energy[i];
        //     }
        // }
        // int p=INT_MIN;
        // for(int i=0;i<n;i++)
        // {
        //     if(experience[i]>p)
        //     {
        //         p=experience[i];
        //     }
        // }
        // int sum=initialEnergy;
        // for(int i=0;i<n;i++)
        // {
        //     if(t==energy[i])
        //     {
        //         sum+=energy[i];
        //         break;
        //     }
        //     sum+=energy[i];
        // }
        // int q=sum-initialEnergy+1;
        // sum=initialExperience;
        // int ans=q;
        // for(int i=0;i<n;i++)
        // {
        //     if(p==experience[i])
        //     {
        //         sum+=experience[i];
        //         break;
        //     }
        //     sum+=experience[i];
        // }
        // q=sum-initialExperience+1;
        // ans+=q;
        // return q;
    }
};