class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        int maxLen = 0;
        int start = 0;

        for(int end = 0; end < s.size(); end++)
        {
            char c = s[end];

            if(seen[c] >= start){
                start = seen[c] + 1;
            }
            seen[c] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};