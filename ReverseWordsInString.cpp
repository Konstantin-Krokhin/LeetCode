class Solution {
public:
    string reverseWords(string s)
    {
        bool str_start = true, space_found = false, end = false, add_space = false;
        int word_len = 0, wrd_stop = 0, j = 0;
        char r[10000];

        for (int i = s.length()-1; i >= 0; i--)
        {
            while (s[i] == ' ')
            {
                if (i > 0) i--;
                else if (s[i] == ' ')
                {
                    end = true;
                    break;
                }

                continue;
            }
            if (end == true)
                break;
            add_space = false;
            wrd_stop = i;

            while (s[i] != ' ' && i >= 0)
            {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                    word_len++;
                if (i > 0) i--;
                else break;
            }

            if (s[i] == ' ')
                space_found = true;

            
            while (i != wrd_stop + 1)
            {
                if (s[i] != ' ') r[j] = s[i];
                else
                {
                    i++;
                    continue;
                }
                j++;
                i++;
            }

            if (i - word_len + 1 > -1) i -= word_len + 1;
            word_len = 0;

            if (i >= 0)
            {
                r[j] = ' ';
                j++;
                add_space = true;
            }
        }
        if (add_space == true) r[--j] = '\0';

        return r;
    }
};