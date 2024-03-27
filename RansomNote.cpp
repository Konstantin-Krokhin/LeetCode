class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        string m = magazine;
        string s = ransomNote;
        int j = 0, i, counter = 0, s_size = s.size(), m_size = m.size();

        while (j < s_size)
        {
            for (i = 0; i < m_size; i++)
            {
                if (s[j] == m[i])
                {
                    m[i] = '0';
                    s[j] = '0';
                    counter++;
                    break;
                }
            }
            
            j++;
        }

        if (counter == s.size())
            return true;
        else
            return false;
    }
};