class Solution {
public:

//same as 3483 unique 3-digit even numbers
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;

        int freq[10] = {0};
        for(int d : digits)
        {
            freq[d]++;
        }

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
            if(valid)
            {
                result.push_back(num); 
                // Loop 100 se 998 tak increasing order me chal raha hai, isliye result already sorted aayega — koi extra sort() call ki zarurat nahi.
            }
        }
        return result;
    }
};