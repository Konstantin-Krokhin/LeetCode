class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size()-1, word_size = 0, word_started = 0;

        while (i >= 0)
        {
            if (s[i] == ' ')
            {
                i--;
                if (word_started == 1)
                    break;
                continue;
            }
            else
            {
                word_started = 1;
                word_size++;
            }
            i--;
        }
        return word_size;
    }
};