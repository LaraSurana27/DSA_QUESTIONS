class Solution {
public:
    int n;

    bool isPalindrome(string &s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j]) 
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int k, int i , int j, vector<vector<int>> &t)
    {
        if(i >= n || j >= n) return 0;

        if(t[i][j] != -1)
        {
            return t[i][j];
        }

        if(isPalindrome(s, i , j))
        {
            int take = 1 + solve(s, k, j+1, j+k, t); //consider that palindrome and i ko j+1 se k length tk try kro

            //dont take conditions even if they are palindrome
            int grow = solve(s, k, i, j+1, t); // sirf j ko badhao
            int slide = solve(s, k, i+1, j+1, t); // dono ko badhao 1-1 se

            return  t[i][j] = max({take, grow, slide});
        }
        else // not palindrome
        {
            int grow = solve(s, k, i, j+1, t); // sirf j ko badhao
            int slide = solve(s, k, i+1, j+1, t); // dono ko badhao 1-1 se   
            return  t[i][j] = max(grow, slide);
        }
    }

    int maxPalindromes(string s, int k) {
       
        // recuraion - memoization approach
        n = s.length();
        if(k == 1) return n;
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        return solve(s, k , 0, k-1, t);
    }
};