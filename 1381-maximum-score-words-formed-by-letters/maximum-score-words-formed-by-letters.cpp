class Solution {
public:
int find(int i, vector<string>& words,vector<int>& score,vector<int> &mp )
{
    if(i==words.size())
       return 0;
    int ans = 0;
    string s = words[i];
    bool f = true;
    int pf =0;
    for(auto it:s)
    {
        pf+=score[it-'a'];
        if(mp[it-'a']>0)
        {
            mp[it-'a']--;
        }
        else
        {
             mp[it-'a']--;
            f = false;
        }
        
       
    }
    if(f)
    {
        ans = max(ans,pf+find(i+1,words,score,mp) );
    }
    for(auto it:s)
    {
         mp[it-'a']++;
    }
    ans = max(ans,find(i+1,words,score,mp) );
    return ans;



}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> mp(26,0);
        for(auto it: letters)
        {
            mp[it-'a']++;
        }
        return find(0,words,score,mp);
    }
};