class Solution {
public:
    bool isAnagram(string s, string t)
    {
        string r = t;
        int j = 0, i, counter = 0, s_size = s.size(), r_size = r.size();

        while (j < s_size)
        {
            for (i = 0; i < r_size; i++)
            {
                if (s[j] == r[i])
                {
                    r[i] = '0';
                    counter++;
                    break;
                }
            }

            if (r[i] != '0')
                return false;
            j++;
        }

        if (counter == t.size() && counter == s.size())
            return true;
        else
            return false;
    }
};