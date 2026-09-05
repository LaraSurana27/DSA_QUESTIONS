class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
     int n = nums.size();
     vector<int> sufMin(n);

     sufMin[n - 1] = nums[n - 1];
     for(int i  = n - 2; i >= 0; i--)
     {
        sufMin[i] = min(sufMin[i + 1], nums[i]);
     }
     int prefMax = INT_MIN;

     for(int i = 0; i < n; i++)
     {
        prefMax = max(prefMax, nums[i]); //instead of calculating seperately we calculate it for each index during that loop only as we want max from 0 to i and not beyond i 
        if(prefMax - sufMin[i] <= k)
        {
            return i;
        }
     }
     return -1;
    }
};