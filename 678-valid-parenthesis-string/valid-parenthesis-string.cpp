class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<int,char>> st;
        int count=0, i=0;
        for(auto it:s)
        {
            if(it=='*')
            {
                count++;
            }
          else  if(it==')' and !st.empty() and st.top().second=='(')
            {
                st.pop();
            }
            else st.push({i,it});
            i++;
        }
        for(int i= s.size()-1;i>=0;i--)
        {
            if(s[i]=='*' and !st.empty())
            {
                int index= st.top().first;
                char c = st.top().second;
                //cout<<c<<" "<<index<<endl;
                if(c==')' and index>i)
                {
                    st.pop();
                }
                else if(c=='(' and index<i)
                {
                    st.pop();

                }
                
            }
        }
        return st.empty();
        
        
    }
};