class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> last(26, -1);  // har character ka "pichla dp value" store karega
        long long dp = 1;  // dp = total distinct subsequences (empty string samet)

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            // NAIVE IDEA:
// Har naye letter 'c' ke aane par, purani saari distinct subsequences (dp count)
// waise hi rehti hain, aur ek copy ban sakti hai jisme har purani subsequence
// ke end mein ye naya letter 'c' add kar diya jaye.
// Isliye total ban jata hai double:
            long long newDp = (2 * dp) % MOD;
            // PROBLEM: agar letter 'c' pehle bhi string mein aa chuka hai,
// toh kuch subsequences REPEAT (duplicate) ho jayengi,
// kyunki purani baar bhi 'c' ko end mein laga kar wahi subsequences bani thi.
            if (last[c] != -1) {
                // FIX:
// Hum har character ka "pichla dp value" store karte hain —
// matlab jab last baar 'c' process hua tha, us waqt dp ki value kya thi.
// Wahi value duplicates ke barabar hoti hai, isliye use subtract kar dete hain.
                newDp = (newDp - last[c] + MOD) % MOD;
            }
            last[c] = dp;   // is character ka purana dp save kar liya
            dp = newDp;
        }

        return (int)((dp - 1 + MOD) % MOD);  // -1 kyunki empty string count nahi karni
    }
};