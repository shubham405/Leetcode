class Solution {
public:
int dp[1001][1001];
 int f(int i, vector<vector<int>>& books, int maxH, int w, int x)
 {
     if(i>=books.size())
     {
        //cout<<maxH<<endl;
         return maxH;
     }
    if(dp[i][w]!=-1)
        return dp[i][w];
    int p = 1e9;
    if(w>=books[i][0])
    {
        p = min(p,f(i+1,books,max(maxH,books[i][1]),w-books[i][0],x));
    }
    int np = maxH+f(i+1,books,books[i][1],x-books[i][0],x);
    //cout<<i<<" "<<p<<" "<<np<<endl;
    return dp[i][w]=min(p,np);
 }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return f(0,books,0,shelfWidth,shelfWidth);
    }
};