class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;

        for(auto &vec : knowledge)
        {
            mp[vec[0]] = vec[1]; // save key value pairs in map for easy retrieval
        }

        string result = "";
        int i = 0;

        while(i < n)
        {
            if(s[i] == '(')
            {
                int j = s.find(")", i+1);
                string temp = s.substr(i+1, j-i-1);
                result += mp.count(temp) ? mp[temp] : "?"; // check for corresponding value of the key found in temp, if it exists in map then add it in result else add ?
                i = j; // start from where we last encountered closing bracket
            }
            else
            {
                result.push_back(s[i]);
            }
            i++;
        }
        return result;
    }
};