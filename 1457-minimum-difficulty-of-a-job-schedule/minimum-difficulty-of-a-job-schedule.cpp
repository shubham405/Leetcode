class Solution {
public:
int dp[12][302];
  int f(int i, vector<int>&job, int d)
  {
    if(i==job.size())
    {
        if(d==0)
          return 0;
        return 1e9;
    }
    if(d<0)
    {
        return 1e9;
    }
    //cout<<i<<" "<<d<<endl;
    if(dp[d][i]!=-1)
        return dp[d][i];
    int ans = 1e9,maxi = job[i];
    for(int x=i;x<job.size();x++)
    {
        maxi = max(maxi,job[x]);
        ans = min(ans,maxi+f(x+1,job,d-1));
    }
    return dp[d][i]=ans;
  }
    int minDifficulty(vector<int>& job, int d) {

        if(d>job.size())
           return -1;
        int n = job.size();
        for(int i = 0;i<n;i++)
        {
            dp[1][i] = *max_element(job.begin()+i,job.end());
        }
        for(int days = 2;days<=d;days++)
        {
            for(int j=0;j<=n-days;j++)
            {
                  int ans = 1e9,maxi = job[j];
                for(int x=j;x<=n-days;x++)
                {
                    maxi = max(maxi,job[x]);
                    ans = min(ans,maxi+dp[days-1][x+1]);
                }
                dp[days][j] = ans;
            }
        }
        return dp[d][0];
    }
};