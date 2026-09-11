class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(int d : digits)
        {
            freq[d]++;
        }
        int count = 0;

        for(int num = 100; num <= 998; num += 2)
        {
            int hundered = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;

            if(hundered == 0) continue;

            int need[10] = {0};
            need[hundered]++;
            need[tens]++;
            need[units]++;

            bool valid = true;
            for(int i = 0; i < 10; i++)
            {
                if(need[i] > freq[i])
                {
                    valid = false;
                    break;
                }
            }
            if(valid) count++;
        }
        return count;
    }
};
/*
3-digit numbers ki range hamesha fixed hoti hai: 100 se 999
Isliye saare 3-digit numbers ko generate karne ki bajaye, hum saare possible 3-digit even numbers (100 to 998) ko iterate karke check karenge
Har number ke liye dekhenge ki wo diye gaye digits se ban sakta hai ya nahi

Steps
1. digits array ki frequency count kar lo (size-10 array, freq[d] = digit d kitni baar available hai)
2. num = 100 se 998 tak loop chalao, step = 2 (sirf even check krne hai)
3. Har num ke liye:
       Uske teen digits nikaalo → hundreds, tens, units
       Agar hundreds == 0 → skip karo (leading zero invalid hai)
4. Us number ke liye required frequency (need[]) bana lo:
      need[hundreds]++, need[tens]++, need[units]++
5. Check karo har digit i ke liye: need[i] <= freq[i]
      Agar sab digits ke liye ye true hai → ye number valid hai, count++
      Agar kisi bhi digit ke liye need[i] > freq[i] → invalid, skip karo
6. Loop khatam hone ke baad count return karo 
*/