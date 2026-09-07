class Solution {
public:
        //bool isHappy(int n) {
        // USING HASHSET 
        /* Ek set bana lo jisme jitne bhi numbers aaye unko store karte jao
        Agar koi number dobara aa gaya (matlab already set mein hai), toh samajh jao ye loop hai → false return karo
        Agar n == 1 ho gaya kabhi bhi → true return karo
        */
        // unordered_set<int> seen;

        // while(n != 1 && seen.find(n) == seen.end())
        // {
        //     seen.insert(n);

        //     int sum = 0;
        //     while(n > 0) //full digit ka square nikalega
        //     {
        //         int digit = n % 10;
        //         sum += digit * digit;
        //         n /= 10;
        //     }
        //     n = sum;
        // }
        // return n == 1;
        //}

        /*FLOYD'S CYCLE DETECTION
        slow ek step aage jata hai, fast do step aage jata hai (jaise Linked List cycle detection mein hota hai)
        Agar number happy hai, toh fast kabhi na kabhi 1 pe pahunch jayega
        Agar loop hai (not happy), toh slow aur fast kisi point pe milenge (kyunki cycle ke andar dono ghoomte rahenge aur eventually same number pe aa jayenge)
        */
        int getNext(int n)
        {
            int sum = 0;
            while(n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            return sum;
        }

        bool isHappy(int n)
        {
            int slow = n;
            int fast = getNext(n);

            while(fast != 1 && slow != fast)
            {
                slow = getNext(slow);
                fast = getNext(getNext(fast));
            }
            return fast == 1;
        }
};