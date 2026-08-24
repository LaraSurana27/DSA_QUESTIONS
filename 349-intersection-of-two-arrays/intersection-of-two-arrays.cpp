class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st(nums1.begin(), nums1.end());

        for(int num : nums2)
        {
            if(st.find(num) != st.end())
            {
                ans.push_back(num);
                st.erase(num); // to avoid duplicate
            }
        }
        return ans;

        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());

        // int i = 0, j = 0;

        // while(i < nums1.size() && j < nums2.size())
        // {
        //     if(nums1[i] < nums2[j])
        //     {
        //         i++;
        //     }
        //     else if(nums1[i] > nums2[j])
        //     {
        //         j++;
        //     }
        //     else
        //     {
        //         if(ans.empty() || ans.back() != nums1[i])
        //         {
        //             ans.push_back(nums1[i]);
        //         }
        //     }
        //     i++;
        //     j++;
        // }
        // return ans;
    }
};