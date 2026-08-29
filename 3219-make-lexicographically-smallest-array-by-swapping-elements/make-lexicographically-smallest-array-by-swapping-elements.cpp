class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // pair of (value, original_index)
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) 
        {
            arr[i] = {nums[i], i};
        
        }
        sort(arr.begin(), arr.end()); 
        
        vector<int> ans(n);
        int i = 0;

        while (i < n) {
            int j = i;
            // group extend karo jab tak consecutive diff <= limit
            while (j + 1 < n && arr[j+1].first - arr[j].first <= limit) {
                j++;
            }
            // group hai arr[i..j], values already sorted hain
            // in indices ko sort karo
            vector<int> indices;
            for (int k = i; k <= j; k++) 
            {
                indices.push_back(arr[k].second);
            }
            sort(indices.begin(), indices.end());
            
            // smallest index pe smallest value, aage badhte jao
            for (int k = 0; k <= j - i; k++) {
                ans[indices[k]] = arr[i + k].first;
            }
            
            i = j + 1; // next group
        }
        
        return ans;
    }
};