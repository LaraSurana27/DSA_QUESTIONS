class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n), sufMin(n);

        prefixMax[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        sufMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            sufMin[i] = min(sufMin[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++)
        {
            if(prefixMax[i] - sufMin[i] <= k)
            {
                return i;
            }
        }
        return -1;
    }
};