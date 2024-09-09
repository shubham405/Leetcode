class Solution {
public:
int dp[11][301];
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
        memset(dp,-1,sizeof(dp));
        return f(0,job,d);
    }
};