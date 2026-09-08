class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        
        // Commas are added at intervals of 1,000 (1,000; 1,000,000; 1,000,000,000; etc.)
        for (long long threshold = 1000; threshold <= n; threshold *= 1000) {
            // Every number from 'threshold' up to 'n' contributes one additional comma
            totalCommas += (n - threshold + 1);
        }
        
        return totalCommas;
    }
};