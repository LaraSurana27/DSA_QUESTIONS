class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            
            if (pairs.count(c)) {
                if (!st.empty() && st.top() == pairs[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } 
            else {
                st.push(c);
            }
        }

        return st.empty();
    }
};