#include "string"

class Solution {
public:
    string intToRoman(int num)
    {
        string finalRoman = "";
        int amountOfMs = num / 1000;
        int amountOfCs = num % 1000 / 100;
        int amountOfXs = num % 100 / 10;
        if (amountOfXs < 1)
            amountOfXs = num / 10;
        int amountOfIs = num % 10;

        if (amountOfMs >= 1)
        {
            for (int i = 0; i < amountOfMs; i++)
                finalRoman.append(1, 'M');
        }
        if (amountOfCs >= 1)
        {
            if (amountOfCs < 4)
                for (int i = 0; i < amountOfCs; i++)
                    finalRoman.append(1, 'C');
            else if (amountOfCs == 4)
                finalRoman.append("CD");
            else if (amountOfCs == 9)
                finalRoman.append("CM");
            else
            {
                finalRoman.append(1, 'D');
                for (int i = 0; i < amountOfCs - 5; i++)
                    finalRoman.append(1, 'C');
            }
        }
        if (amountOfXs >= 1)
        {
            if (amountOfXs < 4)
                for (int i = 0; i < amountOfXs; i++)
                    finalRoman.append(1, 'X');
            else if (amountOfXs == 4)
                finalRoman.append("XL");
            else if (amountOfXs == 9)
                finalRoman.append("XC");
            else if (amountOfXs < 10)
            {
                finalRoman.append(1, 'L');
                for (int i = 0; i < amountOfXs - 5; i++)
                    finalRoman.append(1, 'X');
            }
        }
        if (amountOfIs >= 1)
        {
            if (amountOfIs < 4)
                for (int i = 0; i < amountOfIs; i++)
                    finalRoman.append(1, 'I');
            else if (amountOfIs == 4)
                finalRoman.append("IV");
            else if (amountOfIs == 9)
                finalRoman.append("IX");
            else
            {
                finalRoman.append(1, 'V');
                for (int i = 0; i < amountOfIs - 5; i++)
                    finalRoman.append(1, 'I');
            }
        }

        return finalRoman;
    }
};