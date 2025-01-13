class Solution {
public:
    bool check(vector<pair<int,int>> adj[], int w, int n)
    {
        int count =0;
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            count++;
            for(auto it: adj[node])
            {
                if(it.second>w)
                {
                    continue;
                }
                q.push({it.first});
            }
        }

        return count==n;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int,int>> adj[100001];
        for(auto it:edges)
        {
            adj[it[1]].push_back({it[0],it[2]});
        }
        int l= 1, h=1e6;
        int ans =1e9;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(check(adj,mid,n))
            {
                ans=min(ans,mid);
                h =  mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans==1e9?-1:ans;
    }
};