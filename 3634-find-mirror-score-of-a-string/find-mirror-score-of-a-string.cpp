using ll = long long;

class Solution {
public:
    long long calculateScore(string &s) {
        ll ans =0;
        char x = 'z';
        unordered_map<char,char> mp;
        for(char c = 'a';c<='z';c++)
        {
            mp[c] = x;
            mp[x] = c;
            x--;
        }


        deque<int> track[26];
        track[s[0]-'a'].push_back(0);
        for(int i=1;i<s.size();i++)
        {
            char c = mp[s[i]];
            
            auto &it = track[c-'a'];
            
            if(it.empty())
            {
                track[s[i]-'a'].push_back(i);
                if(track[s[i]-'a'].size()>=50001)
                {
                    track[s[i]-'a'].pop_front();
                }
            }
            else
            {
                ans+=(i-track[c-'a'].back());
                track[c-'a'].pop_back();
            }
            
        }

        return ans;
    }
};