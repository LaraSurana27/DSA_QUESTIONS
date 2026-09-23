class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // recursion and memoization gives TLE
        // use left + right = x
        // find longest subarray with value = total array's sum - value of x so that u are left with minimum no of elements on the left and right side which gives the corract answer -- use hashtable and prefix sum

        int n = nums.size();
        int sum = 0;

        unordered_map<int, int> mp;
        mp[0] = -1; // corner case

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            mp[sum] = i;
        }

        int remainingsum = sum - x;
        if (remainingsum < 0) return -1;

        int longestSubarray  = INT_MIN;
        sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];

            int findSum = sum - remainingsum;

            if(mp.find(findSum) != mp.end())
{
    int idx = mp[findSum];
    if (idx <= i)  // guard against invalid (backwards) subarray
        longestSubarray = max(longestSubarray, i - idx);
}
        }
        return longestSubarray == INT_MIN ? -1 : (n - longestSubarray);

    }
};