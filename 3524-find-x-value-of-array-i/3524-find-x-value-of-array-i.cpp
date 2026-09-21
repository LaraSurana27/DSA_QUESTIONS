class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0); // cnt[v] = subarrays ending at prev index with product%k==v
        
        for (int num : nums) {
            vector<long long> newCnt(k, 0);
            int m = num % k;
            
            // extend previous subarrays
            for (int u = 0; u < k; u++) {
                if (cnt[u] > 0) {
                    int v = (int)((1LL * u * m) % k);
                    newCnt[v] += cnt[u];
                }
            }
            
            // new subarray = just this single element
            newCnt[m] += 1;
            
            cnt = newCnt;
            
            // accumulate into result
            for (int v = 0; v < k; v++) {
                result[v] += cnt[v];
            }
        }
        
        return result;
    }
};