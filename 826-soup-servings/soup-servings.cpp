class Solution {
public:
unordered_map<string, double> dp;
    double f(int a,int b)
    {
        if(a==0 and b)
        {
            return 1;
        }
        if(a==0 and b==0)
        {
           return  0.5;
        }
        if(b==0)
           return 0;
        string key = to_string(a)+to_string(b);
        if(dp.find(key)!=dp.end())
            return dp[key];
        double ans = 0;

        ans=(f(max(a-100,0),b)+f(max(a-75,0),max(b-25,0))+f(max(a-50,0),max(b-50,0))+f(max(a-25,0),max(b-75,0)));
        //cout<<ans<<endl;
        return dp[key]=0.25*ans;
    }
    double soupServings(int n) {
        if(n>=5000)
           return 1;
        return f(n,n);
    }
};