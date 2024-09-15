class Solution {
public:
unordered_map<long long ,int> mp;
int solve(long long i, long long unique, bool can, string &s, int k)
{
    if(i>=s.size())
       return 0;
    long long key = (i << 27) | (unique << 1) | (can);
    if(mp.count(key))
    {
        return mp[key];
    }
    int  newChar  = s[i]-'a';
    //cout<<newChar<<" "<<s[i]<<endl;;
    long long newSet = unique|(1<<newChar);
    int sc = __builtin_popcount(newSet);
    int res=0;
    if(sc>k)
    {
        res = 1+solve(i+1,1<<newChar,can,s,k);
    }
    else
    {
        res = solve(i+1,newSet,can,s,k);
    }
    if(can)
    {
        for(int x =0;x<26;x++)
        {
            long long ns = (1<<x)|unique;
            int nsc = __builtin_popcount(ns);
            if(nsc>k)
            {
                res = max(res,1+solve(i+1,1<<x,0,s,k));
            }
            else
            {
                res = max(res,solve(i+1,ns,0,s,k));
            }
        }
    }
    return mp[key]=res;
    
}
    int maxPartitionsAfterOperations(string s, int k) {
        
        return solve(0,0,1,s,k)+1;
            }
};