class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int fives = 0, tens = 0, twenties = 0, rem;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] > 5)
            {
                rem = bills[i]-5;
                if (rem >= 20 && twenties > 0)
                {
                    int k = 0;
                    for (; k < twenties; k++)
                    {
                        if (rem >= 20)
                            rem -= 20;
                        else
                            break;
                    }
                    twenties -= k;
                }     
                if (rem >= 10 && tens > 0)
                {
                    int k = 0;
                    for (; k < tens; k++)
                    {
                        if (rem >= 10)
                            rem -= 10;
                        else
                            break;
                    }
                    tens -= k;
                }
                if (rem >= 5 && fives > 0)
                {
                    int k = 0;
                    for (; k < fives; k++)
                    {
                        if (rem >= 5)
                            rem -= 5;
                        else
                            break;
                    }
                    fives -= k;
                }    
            }
            if (rem != 0)
                return false;

            if (bills[i] == 5)
                fives++;
            else if (bills[i] == 10)
                tens++;
            else if (bills[i] == 20)
                twenties++;

        }
        return true;
    }
};