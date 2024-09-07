typedef long long ll;
class Solution {
    
public:
    int integerBreak(int n) {

        if(n<=3)
        {
            return n-1;
        }
        ll ans = 1;
        while(n>0)
        {
            if(n<=4)
            {
                ans*=n;
                n=0;
            }
            else
            {
                ans*=3;
                n-=3;
            }
        }
        return ans;

        
    }
};