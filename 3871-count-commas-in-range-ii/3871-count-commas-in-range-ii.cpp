class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        
        if (n >= 1000LL)             totalCommas += n - 1000LL + 1;
        if (n >= 1000000LL)          totalCommas += n - 1000000LL + 1;
        if (n >= 1000000000LL)       totalCommas += n - 1000000000LL + 1;
        if (n >= 1000000000000LL)    totalCommas += n - 1000000000000LL + 1;
        if (n >= 1000000000000000LL) totalCommas += n - 1000000000000000 + 1;
     
        return totalCommas;
    }
};