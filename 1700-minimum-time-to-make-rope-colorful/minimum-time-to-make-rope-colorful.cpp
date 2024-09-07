class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0 ;
        int i = 0 ,j;
        int sum  = accumulate(neededTime.begin(),neededTime.end(),0);
        while(i<colors.size())
        {
            j = i+1;
            if(j<colors.size() and colors[i]==colors[j])
            {
                int mini = neededTime[i];
                
                while(j<colors.size() and colors[j]==colors[i])
                {
                    mini = max(mini,neededTime[j]);
                    j++;
                }
                ans+=mini;
                   
            }
            else
            {
                ans+=neededTime[i];
            }
            i=j;
        }
        cout<<ans<<endl;
        return sum-ans;
    }
};