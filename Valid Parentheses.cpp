class Solution {
public:
    bool isValid(string s)
    {
        int brac1 = 0, brac2 = 0, brac3 = 0, i = 0;
        int flag1 = 0, flag2 = 0, flag3 = 0, k = 0;
        char active;
        char prevbrac[20000];

        while (s[i] != '\0')
        {
            if (s[i] == '(')
            {
                brac1++;
                active = '(';
                prevbrac[k] = '(';
                k++;
                flag1 = 1;
            }
            else if (s[i] == ')')
            {
                if (k > 0) k--;
                if (active == '(' || (brac1 > 0 && '(' == prevbrac[k])) flag1 = 0;
                else return false;
                brac1--;
                active = ' ';
            }
            else if (s[i] == '[')
            {
                brac2++;
                active = '[';
                prevbrac[k] = '[';
                k++;
                flag2 = 1;
            }
            else if (s[i] == ']')
            {
                if (k > 0) k--;
                if (active == '[' || (brac2 > 0 && '[' == prevbrac[k])) flag2 = 0;
                else return false;
                brac2--;
                active = ' ';
            }
            else if (s[i] == '{')
            {
                brac3++;
                active = '{';
                prevbrac[k] = '{';
                k++;
                flag3 = 1;
            }
            else if (s[i] == '}')
            {
                if (k > 0) k--;
                if (active == '{' || (brac3 > 0 && '{' == prevbrac[k])) flag3 = 0;
                else return false;
                brac3--;
                active = ' ';
            }
            
            i++;
        }
        if (brac1 == 0 && brac2 == 0 && brac3 == 0)
            return true;
        else
            return false;
    }
};