class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

       int multiple = k;

       while(st.count(multiple)) // return karta hai: 1 → x set mein present hai else 0 → x set mein present nahi hai
       {
        multiple += k;
       }
       return multiple;
    }
};