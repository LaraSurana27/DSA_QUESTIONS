class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;  
        for (int i = 0; i < s.size(); i++) {
            int reversedAlphaVal = 26 - (s[i] - 'a');  // 'a'->26, 'z'->1
            int position = i + 1;                       // 1-indexed
            sum += reversedAlphaVal * position;
        }
        return (int)sum;
    }
};