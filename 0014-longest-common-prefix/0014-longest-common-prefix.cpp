class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty())
        {
            return "";
        }

        sort(strs.begin(), strs.end());

        string a = strs.front();
        string b = strs.back();

        int i = 0;
        while(i < a.size() && i < b.size() && a[i] == b[i])
        {
            i++;
        }
        return a.substr(0,i);
    }
};