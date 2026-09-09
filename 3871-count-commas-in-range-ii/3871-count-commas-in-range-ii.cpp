#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;
        ll start = 1000;
        // ll lower = 1000;
        // ll comma = 1;

        // while(lower <= n)
        // {
        //     ll upper = lower * 1000 - 1;
        //     if(upper > n) 
        //     {
        //         upper = n;
        //     }
        //     ll count = upper - lower + 1;
        //     result += (count * comma);

        //     lower *= 1000;
        //     comma++;
        // }

        while(start <= n)
        {
            result += (n - start + 1);
            start *= 1000;
        }
        return result;
    }
};