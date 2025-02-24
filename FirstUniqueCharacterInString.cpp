class Solution {
public:
    int firstUniqChar(string s)
    {
        char rep;
        bool end = false, not_found = false;
        int i = 0, j = 0;

        while (!end)
        {
            i = 0;
            rep = s[j];
            while (s[i] != '\0')
            {
                if (rep == s[i] && j != i)
                {
                    not_found = true;
                    break;
                }
                i++;
            }
            if (not_found == false)
                return j;
            if (j >= s.length() - 1)
                end = true;
            j++;
            not_found = false;
        }

        return -1;
    }
};