class Solution {
public:
    int pow(int num, int power)
    {
        int res = num;
        if (power >= 2)
            for (int i = 1; i < power; i++)
                res *= num;
        else if (power == 0)
            res = 1;
        return res;
    }
    int findComplement(int num)
    {
        vector<int> res;
        int resInt = 0;

        while (num > 0)
        {
            if (num % 2)
                res.push_back(0);
            else
                res.push_back(1);
            num /= 2;
        }

        for (int i = 0; i < res.size(); i++)
            if (res[i] == 1)
                resInt += pow(2, i);

        // for (int i = 0; i < res.size(); i++)
        // {
        //     cout << res[i] << endl;
        // }

        return resInt;
    }
};