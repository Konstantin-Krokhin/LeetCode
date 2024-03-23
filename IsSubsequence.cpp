class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int found_char = 0, i_index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i_index; j < t.size(); j++)
            {
                if (s[i] == t[j])
                {
                    found_char++;
                    i_index = j+1;
                    break;
                }
            }
        }

        if (found_char == s.size())
            return true;
        else
            return false;
    }
};