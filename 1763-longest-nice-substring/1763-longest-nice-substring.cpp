class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) return "";

        unordered_set<char> chars(s.begin(), s.end());

        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            char opposite = islower(c) ? toupper(c) : tolower(c);

            if(chars.find(opposite) == chars.end())
            {
                // Yeh character "bad" hai (iska partner nahi mila)
                // Toh iske aage-peeche ke parts mein alag se dhundo
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i+1));

                return left.size() >= right.size() ? left : right;
            }
        }
        // Agar yaha pahunch gaye, matlab poora string nice hai
        return s;
    }
};