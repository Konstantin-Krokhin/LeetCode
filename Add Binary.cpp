class Solution {
public:
    string addBinary(string a, string b)
    {
        int sizeDiff = 0;
        string res;
        int carryon = 0;

        if (a.size() > b.size())
        {
            sizeDiff = a.size() - b.size();
            for (int i = 0; i < sizeDiff; i++)
                b = '0' + b;
        }
        else if (a.size() < b.size())
        {
            sizeDiff = b.size() - a.size();
            for (int i = 0; i < sizeDiff; i++)
                a = '0' + a;
        }

        for (int i = b.size() - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0')
            {
                if (carryon)
                {
                    res = '1' + res;
                    carryon = 0;
                }
                else
                    res = '0' + res;
            }
            else if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
            {
                if (carryon)
                    res = '0' + res;
                else
                    res = '1' + res;
            }
            else if (a[i] == '1' && b[i] == '1')
            {
                if (carryon)
                    res = '1' + res;
                else
                {
                    res = '0' + res;
                    carryon = 1;
                }
            }
        }

        if (carryon)
            res = '1' + res;
        
        return res;
    }
};

/* Second solution */
class Solution {
public:
    string addBinary(string a, string b)
    {
        int sizeDiff = 0;
        string res = "";
        int carry = 0;

        if (a.size() > b.size())
        {
            sizeDiff = a.size() - b.size();
            for (int i = 0; i < sizeDiff; i++)
            {
                b = '0' + b;
            }
        }
        else if (a.size() < b.size())
        {
            sizeDiff = b.size() - a.size();
            for (int i = 0; i < sizeDiff; i++)
            {
                a = '0' + a;
            }
        }

        for (int i = b.size() - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            res = char(sum % 2 + '0') + res;
        }

        if (carry)
            res += '1';
        
        return res;
    }
};