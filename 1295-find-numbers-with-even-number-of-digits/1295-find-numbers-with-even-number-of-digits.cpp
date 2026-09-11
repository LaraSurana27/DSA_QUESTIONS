class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

// math trick
        for(int num : nums)
        {
            int digit = 0;

            while(num > 0)
            {
                num /= 10; // gives u number of digits present in that number
                digit++;
            }
            if(digit % 2 == 0) count++;
        }

// string conversion

        // for(int num : nums)
        // {
        //     string s = to_string(num);
        //     if(s.length() % 2 == 0) count++;
        // }
        return count;
    }
};