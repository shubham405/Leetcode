class Solution {
public:
    int minimumDeletions(string word, int k) {

        vector<int> freq(26,0);
        for(auto it:word)
        {
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end());
        int ans=INT_MAX,sum=0;
        for(int i =0;i<26;i++)
        {
            int f = freq[i];
            int del = sum;
            sum+=f;
            for(int j=i+1;j<26;j++)
            {
                if(freq[j]-f>k)
                {
                    del+= freq[j]-f-k;
                }
            }
            ans=min(ans,del);
        }
        return ans;
        
    }
};