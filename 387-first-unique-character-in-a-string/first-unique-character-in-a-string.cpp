class Solution {
public:
    int firstUniqChar(string s) {


        for(int i =0;i<s.size();i++)
        {
            char c = s[i];
            if(c=='A')
            {
                continue;
            }
            bool f =1;
            for(int  j = i+1;j<s.size();j++)
            {
                if(s[j]==c)
                {
                    s[j]='A';
                    f = 0;
                }
            }
            if(f)
            {
                return i;
            }
        }
    return -1;
        
    }
};