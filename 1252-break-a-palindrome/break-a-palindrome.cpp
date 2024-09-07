class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1)
           return "";
        int x = 0, y=n-1;
        while(x<y)
        {
            if(palindrome[x]=='a')
            {
                x++;
                
                y--;
            }
            else
            {
                palindrome[x]='a';
                return palindrome;
            }
        }
         palindrome[n-1]='b';
        return  palindrome;
    }
};