class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool p = 0;
        int n = grid.size();
        int m  = grid[0].size();
        vector<int> ans;
        for(int i =0;i<n;i++)
        {
            if(i%2)
            {
                for(int j = m-1;j>=0;j--)
                {
                    p = 1-p;
                    if(p)
                    {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            else
            {
                for(int j = 0;j<m;j++)
                {
                    p = 1-p;
                    if(p)
                    {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
        }
        return ans;
        
    }
};