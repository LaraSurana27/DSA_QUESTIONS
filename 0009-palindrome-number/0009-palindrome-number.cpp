class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }

        long int reversenum;
        int y = x;
        int digit;

        while(y>0)
            {
                int digit = y % 10;
                reversenum = reversenum * 10 + digit;
                y = y/10;
                
            }
        if(reversenum == x)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};