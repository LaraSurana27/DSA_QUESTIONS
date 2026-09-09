class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }

        int digit;
        long int revnum = 0;
        int y = x;

        while(y > 0)
        {
            digit = y % 10;
            revnum = revnum * 10 + digit;
            y = y/10;

        }
        if(revnum == x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};