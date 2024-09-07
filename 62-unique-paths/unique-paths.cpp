class Solution {
public:
    int uniquePaths(int m, int n) {
        
        double sum = 1;
  // Calculate the value of n choose r using the binomial coefficient formula
        n = n+m-2;
        int r = m-1;
        for(int i = 1; i <= r; i++){
            sum = sum * (n - r + i) / i;
        }
        cout<<(int)sum<<endl;
        return int(sum);
    }
};