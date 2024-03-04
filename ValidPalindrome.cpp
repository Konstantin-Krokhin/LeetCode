class Solution {
public:
    bool isPalindrome(string s)
    {
        char result[s.size()];
        int j = 0;
        // 65 to 90
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
                result[j] = tolower(s[i]);
            else if ((int)s[i] >= 97 && s[i] <= 122)
                result[j] = s[i];
            else if (isdigit(s[i]) > 0)
                result[j] = s[i];
            else
                j--;
            j++;
        }
        int resSize = j;
        j--;
        for (int i = 0; i < resSize/2; i++, j--)
        {
            if (i >= j) return true;
            if (result[i] != result[j])
                return false;
        }
        return true;
    }
};