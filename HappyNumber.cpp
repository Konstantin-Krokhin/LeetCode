class Solution {
public:
    bool isHappy(int n)
    {
        int res = n, n1 = 0, n2 = 0, rem = 0, prev = 0, count = 0;

        while (res != 1)
        {
            n1 = 0;
            rem = prev = res / 10;
            n2 = res % 10;
            while(rem > 9)
            {
                n1 += ((rem % 10) * (rem % 10));
                rem /= 10;
                if (rem <= 9)
                    n1 += rem * rem;
            }
            if (prev > 9)
                res = n1 + n2 * n2;
            else
            {
                n1 = prev;
                res = n1 * n1 + n2 * n2;
            }
            count++;
            if (count > 1000)
                return false;
        }
        return true;

        // unsigned long long result = n, n1, n2, counter = 0, flag1 = 0, flag2 = 0;
        // while (result != 1)
        // {
        //     n1 = result / 10;
        //     n2 = result % 10;
        //     if (n1 > 9 || n2 > 9)
        //     {
        //         if (n1 > 9)
        //         {
        //             n1 = (n1 % 10) * (n1 % 10) + (n1 / 10) * (n1 / 10);
        //             flag1 = 1;
        //         }
        //         if (n2 > 9)
        //         {
        //             n2 = (n2 % 10) * (n2 % 10) + (n2 / 10) * (n2 / 10);
        //             flag2 = 1;
        //         }
        //         if (flag1 == 1 && flag2 == 1)
        //             result = n1 + n2;
        //         else if (flag2 == 1)
        //             result = n1 * n1 + n2;
        //         else if (flag1 == 1)
        //             result = n1 + n2 * n2;
                
        //         flag1 = 0;
        //         flag2 = 0;
        //     }
        //     if (n1 <= 9 || n2 <= 9)
        //         result = n1 * n1 + n2 * n2;
        //     printf("%d + %d\n", n1, n2);
        //     counter++;
        //     if (counter > 1000)
        //         return false;
        // }
        // return true;
    }
};