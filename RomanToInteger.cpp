class Solution {
public:
    int romanToInt(string s)
    {
        int finalInt = 0;
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == 'I' && s[i+1] == 'V')
            {
                finalInt += 4;
                i++;
                continue;
            }
            if (s[i] == 'I' && s[i+1] == 'X')
            {
                finalInt += 9;
                i++;
                continue;
            }
            if (s[i] == 'I')
            {
                finalInt++;
                continue;
            }
            if (s[i] == 'V')
            {
                finalInt += 5;
                continue;
            }
            if (s[i] == 'X' && s[i+1] == 'L')
            {
                finalInt += 40;
                i++;
                continue;
            }
            if (s[i] == 'X' && s[i+1] == 'C')
            {
                finalInt += 90;
                i++;
                continue;
            }
            if (s[i] == 'X')
            {
                finalInt += 10;
                continue;
            }
            if (s[i] == 'L')
            {
                finalInt += 50;
                continue;
            }
            if (s[i] == 'C' && s[i+1] == 'D')
            {
                finalInt += 400;
                i++;
                continue;
            }
            if (s[i] == 'C' && s[i+1] == 'M')
            {
                finalInt += 900;
                i++;
                continue;
            }
            if (s[i] == 'C')
            {
                finalInt += 100;
                continue;
            }
            if (s[i] == 'D')
            {
                finalInt += 500;
                continue;
            }
            if (s[i] == 'M')
            {
                finalInt += 1000;
                continue;
            }
        }
        return finalInt;
    }
};