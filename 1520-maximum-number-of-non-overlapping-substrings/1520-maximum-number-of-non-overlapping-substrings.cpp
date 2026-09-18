class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        // char c ka minimal valid interval ka right end, ya -1 agar invalid
        auto extend = [&](int c) -> int {
            int l = first[c], r = last[c];
            for (int i = l; i <= r; i++) {
                int d = s[i] - 'a';
                if (first[d] < l) return -1;   // left bahar jaana padega -> invalid
                if (last[d] > r)  r = last[d]; // right extend, loop khud aage scan karega
            }
            return r;
        };

        vector<pair<int,int>> intervals;   // {right, left}
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int r = extend(c);
            if (r != -1) intervals.push_back({r, first[c]});
        }

        sort(intervals.begin(), intervals.end()); // right endpoint se sort

        vector<string> res;
        int prevEnd = -1;
        for (auto &[r, l] : intervals) {
            if (l > prevEnd) {                 // overlap nahi
                res.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }
        return res;
    }
};

/*
Problem ka Core Rule
Substring mein character c ho to c ke saare occurrences usmein aane chahiye
Non-overlapping substrings chahiye, maximum count
Tie → minimum total length
Logic — Step by Step

1. Candidates limited hain

Sirf 26 lowercase letters
Har character ke liye ek minimal valid interval banta hai
Matlab max 26 candidate intervals hi check karne hain, chahe string kitni bhi badi ho

2. first[c] aur last[c] nikalo

Ek pass mein har char ka pehla aur aakhri index store karo

3. Har char ke liye "extend" (closure) karo

Start: l = first[c], r = last[c]
i = l se r tak scan karo:
Andar koi d mila jiska last[d] > r → r ko badhao (right extend)
Andar koi d mila jiska first[d] < l → interval invalid, discard (left kabhi extend nahi karte)
Loop condition i <= r dynamic hai, r badhne par automatically aage scan hoga

4. Valid intervals collect karo

Sirf wahi intervals rakho jo step 3 mein reject nahi hue

5. Laminar property samjho

Ye intervals ya to fully disjoint hote hain ya fully nested
Partial overlap possible hi nahi (warna closure unhe merge kar deta)
Isi property ki wajah se minimum length tie-break automatically solve ho jata hai

6. Greedy — Activity Selection

Intervals ko right endpoint se sort karo
Left to right chalo: if (l > prevEnd) → le lo, prevEnd = r update karo
*/