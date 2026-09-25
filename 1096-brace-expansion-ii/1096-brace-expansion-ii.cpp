class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parseUnion(expression, i);
        return vector<string>(result.begin(), result.end());
    }

private:
    // Cartesian product (concatenation) of two sets
    set<string> combine(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (const string& x : a)
            for (const string& y : b)
                res.insert(x + y);
        return res;
    }

    // Parses a sequence of comma-separated concat-terms, returns their union
    set<string> parseUnion(const string& s, int& i) {
        set<string> result;
        set<string> term = parseConcat(s, i);
        result.insert(term.begin(), term.end());

        while (i < (int)s.size() && s[i] == ',') {
            i++; // skip comma
            term = parseConcat(s, i);
            result.insert(term.begin(), term.end());
        }
        return result;
    }

    // Parses consecutive factors until ',' or '}' or end, returns cartesian product
    set<string> parseConcat(const string& s, int& i) {
        set<string> result = {""};
        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            set<string> factor = parseFactor(s, i);
            result = combine(result, factor);
        }
        return result;
    }

    // Parses a single factor: a letter or a {...} group
    set<string> parseFactor(const string& s, int& i) {
        if (s[i] == '{') {
            i++; // skip '{'
            set<string> res = parseUnion(s, i);
            i++; // skip '}'
            return res;
        } else {
            // single lowercase letter
            string letter(1, s[i]);
            i++;
            return {letter};
        }
    }
};