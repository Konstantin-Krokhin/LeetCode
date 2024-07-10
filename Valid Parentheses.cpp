class Solution {
public:
    bool isValid(string s)
    {
        int brac1 = 0, brac2 = 0, brac3 = 0, i = 0;
        int flag1 = 0, flag2 = 0, flag3 = 0;
        char active;

        while (s[i] != '\0')
        {
            printf("%i, %i, %i, %i\n", i, flag1, flag2, flag3);
            if (s[i] == '(')
            {
                brac1++;
                active = '(';
                flag1 = 1;
            }
            else if (s[i] == ')')
            {
                
                if (active == '(' || brac1 > 0) flag1 = 0;
                else return false;
                brac1--;
            }
            else if (s[i] == '[')
            {
                brac2++;
                active = '[';
                flag2 = 1;
            }
            else if (s[i] == ']')
            {
                
                if (active == '[' || brac2 > 0) flag2 = 0;
                else return false;
                brac2--;
            }
            else if (s[i] == '{')
            {
                brac3++;
                active = '{';
                flag3 = 1;
            }
            else if (s[i] == '}')
            {
                
                if (active == '{' || brac3 > 0) flag3 = 0;
                else return false;
                brac3--;
            }
            
            i++;
        }
        printf("%i, %i, %i, %i\n", i, brac1, brac2, brac3);
        if (brac1 == brac2 == brac3 == 0)
            return true;
        else
            return false;
    }
};