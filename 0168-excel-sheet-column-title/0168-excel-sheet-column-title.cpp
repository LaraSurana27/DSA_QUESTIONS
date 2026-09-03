class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while(columnNumber > 0)
        {
            columnNumber--; // for 1-based calculation rather than 0 based
            char ch = 'A' + (columnNumber % 26); // gives numeric valuye and then converts into char of that number
            result += ch;
            columnNumber /= 26; // gives remainder for processing
        }
        reverse(result.begin(), result.end());
        return result;
    }
};