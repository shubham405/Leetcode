int dp[101][27][101][101];
class Solution {
public:

int f(int i, char prev, int freq, int k, string &s)
{
    if(i==s.size())
       return 0;
    int ans = 1e9;
    if(dp[i][prev-'a'][freq][k]!=-1)
         return dp[i][prev-'a'][freq][k];
    if(s[i] ==prev)
    {
        int newFreq = freq+1;
        if(newFreq==2 || newFreq==10 || newFreq==100 )
        {
            ans = min(ans,1+f(i+1,s[i],newFreq,k,s));
        }
        else
        {
            ans = min(ans,f(i+1,s[i],newFreq,k,s));
        }
    }
    else
    ans = min(ans,1+f(i+1,s[i],1,k,s));
    if(k)
    ans = min(ans,f(i+1,prev,freq,k-1,s));

    return dp[i][prev-'a'][freq][k]=ans;

    
}
    int getLengthOfOptimalCompression(string s, int k) {

        int n =s.size();
        memset(dp,-1,sizeof(dp));
       return f(0,'{',0,k,s);
        
    }
};